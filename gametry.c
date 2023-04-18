#include <stdio.h>
#include <string.h>

#define ROWS 6
#define COLS 7
int c =0;
int game_history[100][ROWS][COLS];  // �C�����v�A�̦h�x�s 100 �B��

struct Player
{
   int move;
   int pos;
   int posboard[6][2];
   int *player[6];
};

int main()
{

    //��l���A
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

    // �N��e���ѽL���A�ƻs�@���[�J�C�����v��
    memcpy(game_history[c], board, sizeof(board));

    //�����C�ӴѤl����m
    PlayGame(rplayer.player,bplayer.player,board,Pstate);


}

//minmax�t��k+�[�W�إ߹C����
void PlayGame(int *Rplayer[6],int *Bplayer[6],int board[ROWS][COLS],int Pstate)
{
    /*�W�h�P�_��
    R���a:
    1.���0-5���@���� ->�i���ʪ�
    2.��ܨ��Vr ---> ������ b---> ������
    3.���o�B�|�J�쪺���p(�ѧ�����)
    */

    char *temp;
    int tValue;//�ȩw
    int boardT[ROWS][COLS];
    memcpy(boardT,board , sizeof(boardT)); //copy

    if(Pstate == 0)
    {
        for(int i=0;i<6;i++)
        {
            if(*Rplayer[i]!=0){

                if(*(Rplayer[i]+1)==0 || Rplayer[i]+1 == Bplayer[0] || Rplayer[i]+1 == Bplayer[1] || Rplayer[i]+1 == Bplayer[2]
                   || Rplayer[i]+1 == Bplayer[3] || Rplayer[i]+1 == Bplayer[4] || Rplayer[i]+1 == Bplayer[5]){ //�ʦp��屼���A�p����
                    printf("Y �� %d\n",i+1);
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
                    printf("Y �� %d\n",i+1);
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
                    printf("Y �� %d\n",i+1);
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
                    printf("Y �� %d\n",j+1);
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
                    printf("Y �� %d\n",j+1);
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
                    printf("Y �� %d\n",j+1);
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
�C���W�h
�i��l�j
6��7 ���ѽL�W�� 6 �Ӭ������M 6 ���Ŧ����C
�C�ӥߤ��鳣���@�Ӥ��� 0 �M 5 �������Ʀr�C
���誺��l��m�O�H�����C �Ĥ@�쪱�a���Ѥl�q��_�C
�b�C�@�����A�Ĥ@�Ӫ��a��ܤ@�Ӭ��������ʡA�M��]�p�G
�C���٨S�������^�ĤG�쪱�a��ܤ@���Ŧ������ʡC


�i���ʡj
1.���a�i�H���ʨ��C�⪺����@���C
2.R���a:���W�������a�u��V�F ���B�n �� �ΪF�n �� ���ʤ���۾F���s���C
3.B���a:�k�U�誺���a�u��N������ʨ�� ���B�_ �� �� ��_���۾F�s���C
4.�p�G�۾F���������⪺����A�h�Ӥ���Q����C
5.�����\���a����ۤv���ߤ���C
6.�p�G�ܤ֦��@�ӦX�k���ʧ@�A�h�����\���a�q�L�C

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
