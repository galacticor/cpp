
/**
 * Stores and takes action for a clicker.
 */
function Clicker(game, i, j) {
  // Current cell of the clicker.
  this.i = i;
  this.j = j;

  // Coordinates of the cell with a sound.
  this.iAlert = -1;
  this.jAlert = -1;

  // If this flag is set, the shortest path distances of the adjacent cells will be updated
  // upon the next move of this clicker.
  this.requireShortestPath = false;

  // Global game instance
  this.game = game;

  // Stores the shortest path distance (shortest path length, absolute offset) for all the adjacent cells
  // and the clicker's cell. This array has length 9.
  this.adjacentDistance = [];
}

/**
 * Moves the clicker. Returns true if the clicker changes its location.
 */
Clicker.prototype.move = function() {
  if (this.iAlert === -1 || (this.iAlert === this.i && this.jAlert === this.j)) {
    return false;
  }
  if (this.requireShortestPath) {
    this.shortestPath();
  }
  var smallestDistance = Infinity;
  var smallestDistanceWithOffset = new Distance(Infinity, Infinity);
  for (var k = 0; k < 9; k++) {
    if (this.adjacentDistance[k].distance < smallestDistance) {
      smallestDistance = this.adjacentDistance[k].distance;
    }
  }
  if (smallestDistance.distance === Infinity) {
    return false; // all cells are blocked, cannot move
  }
  for (var k = 0; k < 8; k++) {
    const ni = this.i + DIRECTION_OFFSET[k][0];
    const nj = this.j + DIRECTION_OFFSET[k][1];
    if (this.adjacentDistance[k].distance === smallestDistance && this.game.getCell(ni, nj) === '.') {
      if (this.adjacentDistance[k].compare(smallestDistanceWithOffset) < 0) {
        smallestDistanceWithOffset = this.adjacentDistance[k];
      }
    }
  }
  for (var k = 0; k < 8; k++) {
    const ni = this.i + DIRECTION_OFFSET[k][0];
    const nj = this.j + DIRECTION_OFFSET[k][1];
    if (this.adjacentDistance[k].compare(smallestDistanceWithOffset) === 0 && this.game.getCell(ni, nj) === '.') {
      this.game.setCell(ni, nj, 'C');
      this.game.setCell(this.i, this.j, '.');
      this.game.clickerInCell[this.i][this.j] = null;
      this.game.clickerInCell[ni][nj] = this;
      this.i = ni;
      this.j = nj;
      this.requireShortestPath = true;
      return true;
    }
  }
  return false;
}

/**
 * Checks if Ellie is in an adjacent cell.
 */
Clicker.prototype.senseEllie = function() {
  for (const offset of DIRECTION_OFFSET) {
    const ni = this.i + offset[0];
    const nj = this.j + offset[1];
    if (!this.game.cellOutOfBound(ni, nj) && this.game.getCell(ni, nj) === 'E') {
      return true;
    }
  }
  return false;
}

/**
 * Starts to trace a sound at cell (i, j).
 */
Clicker.prototype.alert = function(i, j) {
  if (i !== this.iAlert || j !== this.jAlert) {
    this.iAlert = i;
    this.jAlert = j;
    this.requireShortestPath = true;
  }
}

/**
 * Returns if the clicker has heard a sound and is alerted.
 */
Clicker.prototype.isAlerted = function() {
  return this.iAlert !== -1;
}

/**
 * Runs unweighted shortest path from the alerted cell,
 * until all the adjacent cell's shortest paths are determined.
 */
Clicker.prototype.shortestPath = function() {
  const q = [] // queue
  var qHead = 0;
  var qTail = 0;
  const dist = [];
  for (var i = 0; i < this.game.R; i++) {
    const distRow = new Array(this.game.C);
    distRow.fill(Infinity);
    dist.push(distRow);
  }
  dist[this.iAlert][this.jAlert] = 0;
  q[qTail++] = [this.iAlert, this.jAlert];
  while (qHead < qTail) {
    const cur = q[qHead++];
    const ci = cur[0];
    const cj = cur[1];
    for (var k = 0; k < 8; k++) {
      const ni = ci + DIRECTION_OFFSET[k][0];
      const nj = cj + DIRECTION_OFFSET[k][1];
      if (!this.game.cellOutOfBound(ni, nj)) {
        const c = this.game.getCell(ni, nj);
        if (c !== '#' && c !== 'X' && dist[ni][nj] === Infinity) {
          dist[ni][nj] = dist[ci][cj] + 1;
          q[qTail++] = [ni, nj];
        }
      }
    }
    var allComputed = true;
    for (var k = 0; k < 9; k++) {
      const ni = this.i + DIRECTION_OFFSET[k][0];
      const nj = this.j + DIRECTION_OFFSET[k][1];
      if (!this.game.cellOutOfBound(ni, nj) && this.game.getCell(ni, nj) != '#' && this.game.getCell(ni, nj) != 'X' && dist[ni][nj] === Infinity) {
        allComputed = false;
        break;
      }
    }
    if (allComputed) break;
  }
  for (var k = 0; k < 9; k++) {
    this.adjacentDistance[k] = new Distance(Infinity, Infinity);
    const ni = this.i + DIRECTION_OFFSET[k][0];
    const nj = this.j + DIRECTION_OFFSET[k][1];
    if (!this.game.cellOutOfBound(ni, nj)) {
      this.adjacentDistance[k] = new Distance(dist[ni][nj], Math.abs(ni - this.iAlert) + Math.abs(nj - this.jAlert));
    }
  }
  this.requireShortestPath = false;
}


/**
 * Stores the shortest path distance with the absolute offset.
 */
function Distance(distance, offset) {
  this.distance = distance;
  this.offset = offset;
}

/**
 * Compares if the shortest path Distance is smaller than another Distance.
 * Breaks the tie by comparing the absolute offset (Manhattan distance).
 */
Distance.prototype.compare = function(another) {
  if (this.distance !== another.distance) {
    return this.distance - another.distance;
  }
  return this.offset - another.offset;
}
