#include <stdio.h>
#include <string.h>

#define ROWS 6
#define COLS 7
int c =0;
int game_history[100][ROWS][COLS];  // 遊戲歷史，最多儲存 100 步棋

struct Player
{
   int move;
   int pos;
   int posboard[6][2];
   int *player[6];
};

int main()
{

    //初始狀態
    int Pstate = 0;
    int board[ROWS][COLS] = {
                            {1,2,3,0,0,0,0},
                            {4,5,0,0,0,0,0},
                            {6,0,0,0,0,0,0},
                            {0,0,0,0,0,0,6},
                            {0,0,0,0,0,5,4},
                            {0,0,0,0,3,2,1}
                        };
   /*
    int c = 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3-i;j++)
        {
            rplayer.player[c] = board[0+i]+j;
            c++;
        }
    }
    */

    struct Player rplayer,bplayer;
    rplayer.player[0] = &board[0][0];
    rplayer.player[1] = &board[0][1];
    rplayer.player[2] = &board[0][2];
    rplayer.player[3] = &board[1][0];
    rplayer.player[4] = &board[1][1];
    rplayer.player[5] = &board[2][0];

    bplayer.player[0] = &board[5][6];
    bplayer.player[1] = &board[5][5];
    bplayer.player[2] = &board[5][4];
    bplayer.player[3] = &board[4][6];
    bplayer.player[4] = &board[4][5];
    bplayer.player[5] = &board[3][6];

    printf("%d \n",*(bplayer.player[0]-34));

    // 將當前的棋盤狀態複製一份加入遊戲歷史中
    memcpy(game_history[c], board, sizeof(board));

    //紀錄每個棋子的位置
    PlayGame(rplayer.player,bplayer.player,board,Pstate);


}

//minmax演算法+加上建立遊戲樹
void PlayGame(int *Rplayer[6],int *Bplayer[6],int board[ROWS][COLS],int Pstate)
{
    /*規則判斷式
    R玩家:
    1.選擇0-5的一顆棋 ->可移動的
    2.選擇走向r ---> →↓↘ b---> ←↑↖
    3.走這步會遇到的情況(棋局改變)
    */

    char *temp;
    int tValue;//暫定
    int boardT[ROWS][COLS];
    memcpy(boardT,board , sizeof(boardT)); //copy

    if(Pstate == 0)
    {
        for(int i=0;i<6;i++)
        {
            if(*Rplayer[i]!=0){

                if(*(Rplayer[i]+1)==0 || Rplayer[i]+1 == Bplayer[0] || Rplayer[i]+1 == Bplayer[1] || Rplayer[i]+1 == Bplayer[2]
                   || Rplayer[i]+1 == Bplayer[3] || Rplayer[i]+1 == Bplayer[4] || Rplayer[i]+1 == Bplayer[5]){ //缺如何砍掉對方，如何表示
                    printf("Y → %d\n",i+1);
                    temp = Rplayer[i];
                    tValue = *Rplayer[i];
                    *Rplayer[i] = 0;
                    Rplayer[i] = Rplayer[i]+1;
                    *Rplayer[i] = tValue;

                    for(int k=0;k<ROWS;k++){
                        for(int n=0;n<COLS;n++){
                            printf("%d ",board[k][n]);
                        }
                        printf("\n");
                    }
                    PlayGame(Rplayer,Bplayer,board,1);
                    //*Rplayer[i] = tValue;
                    Rplayer[i] = temp;
                    printf("Y next !%d!\n",*Rplayer[i]);
                    c++;
                    memcpy(game_history[c], board, sizeof(board));

                    memcpy(board,boardT, sizeof(boardT));
                }
                if(*(Rplayer[i]+7)==0 || Rplayer[i]+7 == Bplayer[0] || Rplayer[i]+7 == Bplayer[1] || Rplayer[i]+7 == Bplayer[2]
                   || Rplayer[i]+7 == Bplayer[3] || Rplayer[i]+7 == Bplayer[4] || Rplayer[i]+7 == Bplayer[5]){
                    printf("Y ↓ %d\n",i+1);
                    temp = Rplayer[i];
                    tValue = *Rplayer[i];
                    *Rplayer[i] = 0;
                    Rplayer[i] = Rplayer[i]+7;
                    *Rplayer[i] = tValue;

                    for(int k=0;k<ROWS;k++){
                        for(int n=0;n<COLS;n++){
                            printf("%d ",board[k][n]);
                        }
                        printf("\n");
                    }

                    PlayGame(Rplayer,Bplayer,board,1);
                    //*Rplayer[i] = tValue;
                    Rplayer[i] = temp;
                    printf("Y next !%d!\n",*Rplayer[i]);
                    c++;
                    memcpy(game_history[c], board, sizeof(board));


                    memcpy(board,boardT, sizeof(boardT));
                }
                if(*(Rplayer[i]+8)==0 || Rplayer[i]+8 == Bplayer[0] || Rplayer[i]+8 == Bplayer[1] || Rplayer[i]+8 == Bplayer[2]
                   || Rplayer[i]+8 == Bplayer[3] || Rplayer[i]+8 == Bplayer[4] || Rplayer[i]+8 == Bplayer[5]){
                    printf("Y ↘ %d\n",i+1);
                    temp = Rplayer[i];
                    tValue = *Rplayer[i];
                    *Rplayer[i] = 0;
                    Rplayer[i] = Rplayer[i]+8;
                    *Rplayer[i] = tValue;

                    for(int k=0;k<ROWS;k++){
                        for(int n=0;n<COLS;n++){
                            printf("%d ",board[k][n]);
                        }
                        printf("\n");
                    }

                    PlayGame(Rplayer,Bplayer,board,1);
                    //*Rplayer[i] = tValue;
                    Rplayer[i] = temp;
                    printf("Y next !%d!\n",*Rplayer[i]);
                    c++;
                    memcpy(game_history[c], board, sizeof(board));


                    memcpy(board,boardT, sizeof(boardT));
                }
            }

        }
    }
    else
    {
        for(int j=0;j<6;j++)
        {
            if(*Bplayer[j] !=0){
                if(*(Bplayer[j]-1)==0 || Bplayer[j]-1 == Rplayer[0] || Bplayer[j]-1 == Rplayer[1] || Bplayer[j]-1 == Rplayer[2]
                   || Bplayer[j]-1 == Rplayer[3] || Bplayer[j]-1 == Rplayer[4] || Bplayer[j]-1 == Rplayer[5]){
                    printf("Y ← %d\n",j+1);
                    temp = Bplayer[j];
                    tValue = *Bplayer[j];
                    *Bplayer[j] = 0;
                    Bplayer[j] = Bplayer[j]-1;
                    *Bplayer[j] = tValue;

                    for(int k=0;k<ROWS;k++){
                        for(int n=0;n<COLS;n++){
                            printf("%d ",board[k][n]);
                        }
                        printf("\n");
                    }

                    PlayGame(Rplayer,Bplayer,board,0);
                    //*Bplayer[j] = tValue;
                    Bplayer[j] = temp;
                    printf("Y next !%d!\n",*Bplayer[j]);
                    c++;
                    memcpy(game_history[c], board, sizeof(board));
                    memcpy(board,boardT, sizeof(boardT));
                }
                if(*(Bplayer[j]-7)==0 || Bplayer[j]-7 == Rplayer[0] || Bplayer[j]-7 == Rplayer[1] || Bplayer[j]-7 == Rplayer[2]
                   || Bplayer[j]-7 == Rplayer[3] || Bplayer[j]-7 == Rplayer[4] || Bplayer[j]-7 == Rplayer[5]){
                    printf("Y ↑ %d\n",j+1);
                    temp = Bplayer[j];
                    tValue = *Bplayer[j];
                    *Bplayer[j] = 0;
                    Bplayer[j] = Bplayer[j]-7;
                    *Bplayer[j] = tValue;

                    for(int k=0;k<ROWS;k++){
                        for(int n=0;n<COLS;n++){
                            printf("%d ",board[k][n]);
                        }
                        printf("\n");
                    }

                    PlayGame(Rplayer,Bplayer,board,0);
                    //*Bplayer[j] = tValue;
                    Bplayer[j] = temp;
                    printf("Y next !%d!\n",*Bplayer[j]);
                    c++;
                    memcpy(game_history[c], board, sizeof(board));
                    memcpy(board,boardT, sizeof(boardT));
                }
                if(*(Bplayer[j]-8)==0 || Bplayer[j]-8 == Rplayer[0] || Bplayer[j]-8 == Rplayer[1] || Bplayer[j]-8 == Rplayer[2]
                   || Bplayer[j]-8 == Rplayer[3] || Bplayer[j]-8 == Rplayer[4] || Bplayer[j]-8 == Rplayer[5]){
                    printf("Y ↖ %d\n",j+1);
                    temp = Bplayer[j];
                    tValue = *Bplayer[j];
                    *Bplayer[j] = 0;
                    Bplayer[j] = Bplayer[j]-8;
                    *Bplayer[j] = tValue;

                    for(int k=0;k<ROWS;k++){
                        for(int n=0;n<COLS;n++){
                            printf("%d ",board[k][n]);
                        }
                        printf("\n");
                    }

                    PlayGame(Rplayer,Bplayer,board,0);
                    //*Bplayer[j] = tValue;
                    Bplayer[j] = temp;
                    printf("Y next !%d!\n",*Bplayer[j]);
                    c++;
                    memcpy(game_history[c], board, sizeof(board));
                    memcpy(board,boardT, sizeof(boardT));
                }
            }
        }

    }


}

void gamestate()
{
//



}


/*
遊戲規則
【初始】
6×7 的棋盤上有 6 個紅色方塊和 6 個藍色方塊。
每個立方體都有一個介於 0 和 5 之間的數字。
雙方的初始位置是隨機的。 第一位玩家的棋子從西北。
在每一輪中，第一個玩家選擇一個紅色方塊移動，然後（如果
遊戲還沒有結束）第二位玩家選擇一個藍色方塊移動。


【移動】
1.玩家可以移動其顏色的任何一塊。
2.R玩家:左上角的玩家只能向東 →、南 ↓ 或東南 ↘ 移動方塊相鄰的廣場。
3.B玩家:右下方的玩家只能將方塊移動到西 ←、北 ↑ 或 西北↖相鄰廣場。
4.如果相鄰方塊中有對手的方塊，則該方塊被捕獲。
5.不允許玩家捕獲自己的立方體。
6.如果至少有一個合法的動作，則不允許玩家通過。

  if(state == 0) //redplayer
    {
        if()
        {


        }



    }
    else //blueplayer
    {


    }

*/
