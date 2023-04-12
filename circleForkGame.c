#include <stdio.h>

// 定義遊戲狀態
#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2

// 定義遊戲棋盤大小
#define ROWS 3
#define COLS 3

// 定義搜索深度
#define MAX_DEPTH 9

// 定義遊戲樹節點
typedef struct Node {
    int board[ROWS][COLS];
    int score;
    struct Node* child[ROWS*COLS];
    int num_child;
} Node;

// 初始化遊戲樹
Node* init_game_tree(int board[ROWS][COLS], int player);

// 創建遊戲樹節點
Node* create_node(int board[ROWS][COLS], int player);

// 評估函數
int evaluate(int board[ROWS][COLS], int player);

// 遞歸搜索
int search(Node* node, int depth, int alpha, int beta, int player);

// Alpha-Beta剪枝
int alpha_beta_pruning(int score, int player, int alpha, int beta);

// 找到最佳行動
void find_best_move(int board[ROWS][COLS], int player);

// 模擬玩家下棋
void player_move(int board[ROWS][COLS], int player);

// 模擬電腦下棋
void computer_move(int board[ROWS][COLS], int player);

int main() {
    int board[ROWS][COLS] = {EMPTY};
    int player = PLAYER_X;

    // 玩家先手下棋
    player_move(board, player);

    return 0;
}

Node* init_game_tree(int board[ROWS][COLS], int player) {
    Node* node = create_node(board, player);
    int i, j;

    // 搜尋深度未達到最大值，遞歸創建子節點
    if (search_depth < MAX_DEPTH) {
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == EMPTY) {
                    int child_board[ROWS][COLS];
                    memcpy(child_board, board, sizeof(child_board));
                    child_board[i][j] = player;
                    node->child[node->num_child] = init_game_tree(child_board, 3 - player);
                    node->num_child++;
                }
            }
        }
    }

    return node;
}

Node* create_node(int board[ROWS][COLS], int player) {
    Node* node = (Node*)malloc(sizeof(Node));
    memcpy(node->board, board, sizeof(node->board));
    node->score = evaluate(board, player);
    node->num_child = 0;
    return node;
}

int evaluate(int board[ROWS][COLS], int player) {
    // TODO: 計算評分
}

int search(Node* node, int depth, int alpha, int beta, int player) {
    int i, child_score;

    // 遞歸終止條件
    if (depth == MAX_DEPTH || node->score != 0) {
        return node->score;
    }

    // Max玩家
    if (player == PLAYER_X) {
        for (i = 0; i < node->num_child; i++) {
            child_score = search(node->child[i], depth + 1, alpha, beta, PLAYER_O);
            alpha = alpha_beta_pruning(child_score, player, alpha, beta);
            if (alpha >= beta) {
                break;
            }
        }
        return alpha;
    }
    // Min玩家
    else {
        for (i = 0; i < node->num_child; i++) {
            child_score = search(node->child[i], depth + 1, alpha, beta, PLAYER_X);
            beta = alpha_beta_pruning(child_score, player, alpha, beta);
            if (beta <= alpha) {
                break;
            }
        }
        return beta;
    }
}
