// Stores all areas, indexed by area names
const areas = {};

// The game instance of class Game with all the game states.
var game = undefined;

// Current action type, 'none', 'walk' or 'brick'.
var actionType = 'none';

// Size of each cell when rendered (in pixels).
const CELL_SIZE_PX = 30;
// Wait time period between two consecutive clicker actions.
const CLICKER_MOVE_GAP_MS = 200;

// How many cells to show in horizontal and vertical dimension in the web game.
const WEBGAME_VIEW_SIZE = 30;

// Direction offset in 9 directions (8 adjacent + itself). These are in screen coordinates.
const DIRECTION_OFFSET = [
  [-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1], [0, 0]
];

/**
 * Returns the ID string of an interactive cell.
 */
function cellId(i, j) {
  return 'cell_' + i + '_' + j;
}

/**
 * Displays a message on the screen.
 */
function showMessage(message) {
  $('#message').text(message);
}
