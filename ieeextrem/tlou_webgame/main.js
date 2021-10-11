// Starts the webgame after all area js are loaded.
$(document).ready(() => main());

/**
 * Creates the area select dropdown.
 */
function createAreaSelectOptions() {
  const $areaSelect = $('#area-select');
  for (const areaName in areas) {
    $areaSelect.append(new Option(areaName, areaName));
  }
  $areaSelect.attr('value', Object.keys(areas)[0]);

  $('#start').click(() => {
    const newArea = $areaSelect.val();
    const confirmed = confirm('Start a new area? The current area progress will be lost.')
    if (confirmed) {
      loadArea(newArea);
    }
  });
}

/**
 * Handles brick throw button click.
 */
function createThrowBrickHandler() {
  $('#throw-brick')
    .click(() => {
      if (actionType === 'walk') {
        actionType = 'brick';
      } else if (actionType == 'brick') {
        actionType = 'walk';
      }
      draw();
      waitForAction();
    });
}

/**
 * Updates the "Throw Brick" button and the remaining brick count.
 */
function updateBrickUi() {
  const $button = $('#throw-brick');
  $('#bricks').text(game.B);
  if (game.B === 0) {
    $button.prop('disabled', true);
  } else {
    $button.prop('disabled', false);
  }
  if (actionType === 'brick') {
    $button.text('Cancel Throw');
  } else if (actionType === 'walk') {
    $button.text('Throw Brick');
  } else {
    $button.prop('disabled', true);
  }
}

/**
 * Loads the given area into play.
 */
function loadArea(areaNameToLoad) {
  areaName = areaNameToLoad;
  const area = areas[areaName];
  game = new Game(area);

  actionType = 'walk';
  draw();
  waitForAction();
}

/**
 * Draws the current game map.
 * Updates the number of bricks.
 */
function draw() {
  updateBrickUi();
  const $interactive = $('#interactive');
  $interactive.empty();
  $('#canvas')
    .attr('width', WEBGAME_VIEW_SIZE * CELL_SIZE_PX)
    .attr('height', WEBGAME_VIEW_SIZE * CELL_SIZE_PX);
  const canvas = $('#canvas')[0];
  const ctx = canvas.getContext('2d');
  ctx.font = '32px courier';
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  // Draw grid
  ctx.lineWidth = 1;
  ctx.strokeStyle = '#999';
  for (var i = 0; i <= WEBGAME_VIEW_SIZE; i++) {
    ctx.moveTo(0, i * CELL_SIZE_PX);
    ctx.lineTo(WEBGAME_VIEW_SIZE * CELL_SIZE_PX, i * CELL_SIZE_PX);
    ctx.stroke();
  }
  for (var j = 0; j <= WEBGAME_VIEW_SIZE; j++) {
    ctx.moveTo(j * CELL_SIZE_PX, 0);
    ctx.lineTo(j * CELL_SIZE_PX, WEBGAME_VIEW_SIZE * CELL_SIZE_PX);
    ctx.stroke();
  }

  // Draw cell
  const viewSpan = Math.floor(WEBGAME_VIEW_SIZE / 2);
  for (var i = game.Ei - viewSpan; i <= game.Ei + viewSpan; i++) {
    for (var j = game.Ej - viewSpan; j <= game.Ej + viewSpan; j++) {
      const c = game.cellOutOfBound(i, j) ? '?' : game.getCell(i, j);
      if (c == '#') {
        ctx.fillStyle = '#333';
      } else {
        ctx.fillStyle = 'white';
      }
      const vi = i - game.Ei + viewSpan;
      const vj = j - game.Ej + viewSpan;
      ctx.beginPath();
      ctx.rect(vj * CELL_SIZE_PX + 1, vi * CELL_SIZE_PX + 1, CELL_SIZE_PX - 2, CELL_SIZE_PX - 2);
      ctx.fill();

      if (c == 'X' || c == 'E' || c == 'C') {
        ctx.fillStyle = 'black';
        if (c == 'C') {
          const clicker = game.getClickerInCell(i, j);
          if (clicker !== null && clicker.isAlerted()) {
            ctx.fillStyle = 'red';
          }
        }
        ctx.fillText(c, vj * CELL_SIZE_PX + 5, vi * CELL_SIZE_PX + CELL_SIZE_PX - 4);
      } else if (c == '?') {
        ctx.moveTo(vj * CELL_SIZE_PX, vi * CELL_SIZE_PX);
        ctx.lineTo(vj * CELL_SIZE_PX + CELL_SIZE_PX, vi * CELL_SIZE_PX + CELL_SIZE_PX);
        ctx.stroke();
      }

      if (Math.abs(Math.abs(i - game.Ei), Math.abs(j - game.Ej)) <= 7) {
        $('<div></div>')
          .attr('id', cellId(i, j))
          .addClass('interactive-cell')
          .css('left', vj * CELL_SIZE_PX)
          .css('top', vi * CELL_SIZE_PX)
          .click(onCellClicked)
          .appendTo($interactive);
      }
    }
  }
}

/**
 * Handles the click of an interactive cell to walk or throw a brick.
 */
function onCellClicked(evt) {
  const idTokens = evt.target.id.split('_');
  if (!$(evt.target).hasClass('highlighted')) {
    return;
  }
  const i = +idTokens[1];
  const j = +idTokens[2];
  if (actionType === 'walk') {
    takeWalkAction(i - game.Ei, j - game.Ej);
  } else if (actionType === 'brick') {
    takeBrickAction(i - game.Ei, j - game.Ej);
  }
}

/**
 * Waits for player's action.
 * This by default expects a walk action and highlights the walkable cell.
 * The player may click the "Throw" button to enter the brick throwing mode.
 */
function waitForAction() {
  if (actionType === 'walk') {
    waitForWalkAction();
  } else if (actionType === 'brick') {
    waitForBrickAction();
  }
}

/**
 * Highlights the adjacent walkable cells and makes them clickable for walk.
 */
function waitForWalkAction() {
  for (const offset of DIRECTION_OFFSET) {
    const i = game.Ei + offset[0];
    const j = game.Ej + offset[1];
    if (!game.cellOutOfBound(i, j) && (game.getCell(i, j) === '.' || game.getCell(i, j) === 'X' || game.getCell(i, j) === 'E')) {
      $('#' + cellId(i, j)).addClass('highlighted');
    }
  }
}

/**
 * Highlights the cells in the surroundings and makes them clickable for throwing a brick.
 */
function waitForBrickAction() {
  for (var di = -7; di <= 7; di++) {
    for (var dj = -7; dj <= 7; dj++) {
      const i = game.Ei + di;
      const j = game.Ej + dj
      if (!game.cellOutOfBound(i, j) && game.getCell(i, j) === '.') {
        $('#' + cellId(i, j)).addClass('highlighted');
      }
    }
  }
}

/**
 * Executes a walk action. (di, dj) are screen coordinates and di = -dy, dj = dx in the problem.
 */
function takeWalkAction(di, dj) {
  const nextEi = game.Ei + di;
  const nextEj = game.Ej + dj;
  if (game.cellOutOfBound(nextEi, nextEj)) {
    gameOver('Ellie walked out of the area.', nextEi, nextEj);
    return;
  }
  const c = game.getCell(nextEi, nextEj);
  if (c === '#') {
    gameOver('Ellie walked into a blocked cell.', nextEi, nextEj);
    return;
  }
  if (c === 'C') {
    gameOver('Ellie walked into a clicker and died.', nextEi, nextEj);
    return;
  }
  game.setCell(nextEi, nextEj, 'E');
  if (game.Ei !== nextEi || game.Ej !== nextEj) {
    game.setCell(game.Ei, game.Ej, '.');
  }
  if (c == 'X') {
    gameSuccess(nextEi, nextEj);
    return;
  }
  game.Ei = nextEi;
  game.Ej = nextEj;
  draw();
  game.makeSound(nextEi, nextEj);
  moveClickers();
}

/**
 * Executes a brick throwing action. (di, dj) are screen coordinates and di = -dy, dj = dx in the problem.
 */
function takeBrickAction(di, dj) {
  const bi = game.Ei + di;
  const bj = game.Ej + dj;
  if (game.cellOutOfBound(bi, bj)) {
    gameOver('Ellie throws a brick out of the area.', bi, bj);
    return;
  }
  const c = game.getCell(bi, bj);
  if (c === '#') {
    gameOver('Ellie throws a brick at a blocked cell.', bi, bj);
    return;
  }
  if (c === 'X') {
    gameOver('Ellie throws a brick at the exit.', bi, bj);
    return;
  }
  if (c === 'C') {
    gameOver('Ellie throws a brick at a clicker.', bi, bj);
    return;
  }
  draw();
  game.B--;
  game.makeSound(bi, bj);
  moveClickers();
}

/**
 * Moves the clickers one by one.
 * The topmost and then leftmost clicker moves first.
 */
function moveClickers() {
  game.orderClickers();
  actionType = 'none';
  var clickerIndex = 0;
  var interval = setInterval(() => {
    if (clickerIndex === game.clickers.length) {
      clearInterval(interval);
      actionType = 'walk';
      draw();
      waitForAction();
      showMessage('');
    } else {
      while (clickerIndex < game.clickers.length) {
        showMessage('Awaiting clicker actions... ' + (clickerIndex + 1) + '/' + game.clickers.length);
        const clicker = game.clickers[clickerIndex];
        clickerIndex++;
        if (clicker.senseEllie()) {
          gameOver('A clicker grabbed and killed Ellie.', clicker.i, clicker.j);
          clearInterval(interval);
          return;
        }
        if (clicker.move()) break;
      }
      draw();
    }
  }, CLICKER_MOVE_GAP_MS);
}

/**
 * Ends the game by game over.
 */
function gameOver(message, badi, badj) {
  showMessage('[GAME OVER] ' + message);
  actionType = 'none';
  draw();
  $('#' + cellId(badi, badj)).addClass('bad');
}

/**
 * Ends the game by successfully reaching the exit.
 */
function gameSuccess(ei, ej) {
  showMessage('[SURVIVED] Ellie reached the exit.');
  actionType = 'none';
  draw();
  $('#' + cellId(ei, ej)).addClass('success');
}

/**
 * Entry of the entire game.
 */
function main() {
  // Create UI elements and their handlers.
  createAreaSelectOptions();
  createThrowBrickHandler();

  // Load the sample area by default.
  loadArea(Object.keys(areas)[0]);
}
