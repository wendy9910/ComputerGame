#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int color; // 0: red, 1: blue
    int number; // number between 0 and 5
    Position pos;
} Cube;

typedef struct {
    Cube cubes[ROWS*COLS];
    int turn; // 0: red, 1: blue
    int board[ROWS][COLS]; // board[x][y] = 0: empty, 1: red, 2: blue
} GameState;

void init_game(GameState* game) {
    // initialize the game state, including the board and the cubes
}

int is_game_over(GameState* game) {
    // check if the game is over
}

int is_valid_move(GameState* game, int color, Position from, Position to) {
    // check if the move is valid
}

void move_cube(GameState* game, int color, Position from, Position to) {
    // move the cube from "from" to "to"
}

void play_game() {
    GameState game;
    init_game(&game);

    while (!is_game_over(&game)) {
        // print the board and ask the current player to make a move
        // check if the move is valid, and if so, move the cube
        // switch to the next player
    }

    // print the final result of the game
}

int main() {
    play_game();
    return 0;
}


