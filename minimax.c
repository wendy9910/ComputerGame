#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROWS 6
#define COLS 7

int value;

typedef struct {
    int board[ROWS][COLS];
} Board;


// 遊戲樹的節點
typedef struct node {
    Board* board;
    int move[3];
    int player;
    int score;
    int num_child;
    struct node** child;
} Node;

int main()
{
    Board mainboard;



}

void fun_alphabeta(d,node,maxP, v, A, B)
{
    if(d==3):
        return v[node];
    if(maxP)
    {
        best = minimum;
        for(int i=0;i<3;i++)
        {
            value = fun_alphabeta(d+1,node*2+i,False, v, A, B)
            best = max(best,value);
            A = max(A,best);
            if(B<=A):
                    break;
        }
        return best;

    }
    else
    {
        best = maximum;
        for(int i=0;i<3;i++)
        {
            value = fun_alphabeta(d+1,node*2+i,False, v, A, B)
            best = min(best,value);
            B = max(B,best);
            if(B<=A):
                    break;
        }
        return best;
    }


}

