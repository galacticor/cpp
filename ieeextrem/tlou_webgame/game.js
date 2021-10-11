/**
 * Global game instance.
 * Stores all the game states.
 */
function Game(area) {
  // Size of the area.
  this.R = area.R;
  this.C = area.C;

  // Number of bricks left.
  this.B = area.B;

  // The character map of the area.
  // This will be updated when the game is played.
  this.map = area.map;

  // List of clickers in the map.
  this.clickers = [];
  // Screen coordinates of Ellie.
  this.Ei = -1;
  this.Ej = -1;
  // Screen coordinates of Exit.
  this.Xi = -1;
  this.Xj = -1;

  // 2D array that maps a cell to a clicker.
  this.clickerInCell = [];

  // Initalizes the game.
  this.init();
}

/**
 * Initializes the game from input area data.
 */
Game.prototype.init = function() {
  const mapRows = this.map.split('\n');
  // remove the first empty row for solely formatting purpose
  this.map = mapRows.filter(row => row);

  for (var i = 0; i < this.R; i++) {
    const clickerInCellRow = [];
    for (var j = 0; j < this.C; j++) {
      var clicker = null;
      if (this.map[i][j] == 'E') {
        this.Ei = i;
        this.Ej = j;
      } else if (this.map[i][j] == 'X') {
        this.Xi = i;
        this.Xj = j;
      } else if (this.map[i][j] == 'C') {
        clicker = new Clicker(this, i, j);
        this.clickers.push(clicker);
      }
      clickerInCellRow.push(clicker);
    }
    this.clickerInCell.push(clickerInCellRow);
  }
}

/**
 * Gets the character value of cell (i, j).
 */
Game.prototype.getCell = function(i, j) {
  return this.map[i][j];
}

/**
 * Sets the character value of cell (i, j) to character c.
 */
Game.prototype.setCell = function(i, j, c) {
  this.map[i] = this.map[i].substr(0, j) + c + this.map[i].substr(j + 1);
}

/**
 * Returns the clicker standing in cell (i, j),
 * or null if there is no such clicker.
 */
Game.prototype.getClickerInCell = function(i, j) {
  return this.clickerInCell[i][j];
}

/**
 * Returns if the screen coordinates (i, j) is outside the area boundary.
 */
Game.prototype.cellOutOfBound = function(i, j) {
  return i < 0 || i >= this.R || j < 0 || j >= this.C;
}

/**
 * Makes a sound in cell (i, j).
 * This will alert all clickers in the vicinity of this cell.
 */
Game.prototype.makeSound = function(i, j) {
  for (var di = -2; di <= 2; di++) {
    for (var dj = -2; dj <= 2; dj++) {
      const vi = i + di;
      const vj = j + dj;
      if (!this.cellOutOfBound(vi, vj)) {
        const clicker = this.getClickerInCell(vi, vj);
        if (clicker !== null) {
          clicker.alert(i, j);
        }
      }
    }
  }
}

/**
 * Orders the clickers by their locations.
 * The topmost and then leftmost clicker moves first.
 */
Game.prototype.orderClickers = function() {
  this.clickers.sort((a, b) => {
    if (a.i !== b.i) {
      return a.i - b.i;
    }
    return a.j - b.j;
  });
}
