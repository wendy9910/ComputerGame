#include <stdio.h>
#include <string.h>

#define ROWS 6
#define COLS 7


char game_history[100][ROWS][COLS];  // 遊戲歷史，最多儲存 100 步棋

struct Player
{
   int move;
   int pos;
   int posboard[6][2];
   char *player[6];
};

int main()
{

    //初始狀態
    int Pstate = 0;
    char board[ROWS][COLS] = {
                            {'0','1','2',' ',' ',' ',' '},
                            {'3','4',' ',' ',' ',' ',' '},
                            {'5',' ',' ',' ',' ',' ',' '},
                            {' ',' ',' ',' ',' ',' ','5'},
                            {' ',' ',' ',' ',' ','4','3'},
                            {' ',' ',' ',' ','2','1','0'}
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
    rplayer.player[0] = board[0];
    rplayer.player[1] = board[0]+1;
    rplayer.player[2] = board[0]+2;
    rplayer.player[3] = board[1];
    rplayer.player[4] = board[1]+1;
    rplayer.player[5] = board[2];

    bplayer.player[0] = board[5]+6;
    bplayer.player[1] = board[5]+5;
    bplayer.player[2] = board[5]+4;
    bplayer.player[3] = board[4]+6;
    bplayer.player[4] = board[4]+5;
    bplayer.player[5] = board[3]+6;

    printf("%c #",*(rplayer.player[0]+1));


    // 將當前的棋盤狀態複製一份加入遊戲歷史中
    memcpy(game_history[0], board, sizeof(board));

    //紀錄每個棋子的位置
    PlayGame(rplayer.player,bplayer.player,board,Pstate);


}

//minmax演算法+加上建立遊戲樹
void PlayGame(char *Rplayer[6],char *Bplayer[6],char board[ROWS][COLS],int Pstate)
{
    /*規則判斷式

    R玩家:
    1.選擇0-5的一顆棋 ->可移動的
    2.選擇走向r ---> →↓↘ b---> ←↑↖
    3.走這步會遇到的情況(棋局改變)

    */


    if(Pstate == 0)
    {
        for(int i=0;i<6;i++)
        {
            if(*(Rplayer[i]+1)==' '){
                printf("Y → %d\n",i);
            }
            if(*(Rplayer[i]+7)==' '){
                printf("Y ↓ %d\n",i);
            }
            if(*(Rplayer[i]+8)==' '){
                printf("Y ↘ %d\n",i);
            }

        }
    }
    else
    {



    }


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
