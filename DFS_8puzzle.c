#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 3

typedef struct {
    int x, y;
} Move;

Move moves[] = {
    {0, -1}, // ¤W
    {1, 0},  // ¥k
    {0, 1},  // ¤U
    {-1, 0}  // ¥ª
};

int goal[BOARD_SIZE][BOARD_SIZE] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

int visited[BOARD_SIZE * BOARD_SIZE][BOARD_SIZE][BOARD_SIZE];
int found_solution = 0;

int is_valid_move(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

void dfs(int board[BOARD_SIZE][BOARD_SIZE], int depth, int x, int y) {
    if (found_solution) {
        return;
    }

    if (depth > 30) {
        return;
    }

    if (memcmp(board, goal, sizeof(goal)) == 0) {
        printf("Found solution!\n");
        found_solution = 1;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int new_x = x + moves[i].x;
        int new_y = y + moves[i].y;

        if (is_valid_move(new_x, new_y)) {
            int temp = board[new_x][new_y];
            board[new_x][new_y] = 0;
            board[x][y] = temp;

            if (!visited[board[0][0]][board[0][1]][board[0][2]]) {
                visited[board[0][0]][board[0][1]][board[0][2]] = 1;
                dfs(board, depth + 1, new_x, new_y);
                visited[board[0][0]][board[0][1]][board[0][2]] = 0;
            }

            board[x][y] = 0;
            board[new_x][new_y] = temp;
        }
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {2, 8, 3},
        {1, 6, 4},
        {7, 0, 5}
    };
    visited[board[0][0]board[0][1][board[0][2]]] = 1;


}

