#include <stdio.h>

// �w�q�C�����A
#define EMPTY 0
#define PLAYER_X 1
#define PLAYER_O 2

// �w�q�C���ѽL�j�p
#define ROWS 3
#define COLS 3

// �w�q�j���`��
#define MAX_DEPTH 9

// �w�q�C����`�I
typedef struct Node {
    int board[ROWS][COLS];
    int score;
    struct Node* child[ROWS*COLS];
    int num_child;
} Node;

// ��l�ƹC����
Node* init_game_tree(int board[ROWS][COLS], int player);

// �ЫعC����`�I
Node* create_node(int board[ROWS][COLS], int player);

// �������
int evaluate(int board[ROWS][COLS], int player);

// ���k�j��
int search(Node* node, int depth, int alpha, int beta, int player);

// Alpha-Beta�ŪK
int alpha_beta_pruning(int score, int player, int alpha, int beta);

// ���̨Φ��
void find_best_move(int board[ROWS][COLS], int player);

// �������a�U��
void player_move(int board[ROWS][COLS], int player);

// �����q���U��
void computer_move(int board[ROWS][COLS], int player);

int main() {
    int board[ROWS][COLS] = {EMPTY};
    int player = PLAYER_X;

    // ���a����U��
    player_move(board, player);

    return 0;
}

Node* init_game_tree(int board[ROWS][COLS], int player) {
    Node* node = create_node(board, player);
    int i, j;

    // �j�M�`�ץ��F��̤j�ȡA���k�Ыؤl�`�I
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
    // TODO: �p�����
}

int search(Node* node, int depth, int alpha, int beta, int player) {
    int i, child_score;

    // ���k�פ����
    if (depth == MAX_DEPTH || node->score != 0) {
        return node->score;
    }

    // Max���a
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
    // Min���a
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
