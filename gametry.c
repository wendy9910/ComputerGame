#include <stdio.h>
#include <string.h>

#define ROWS 6
#define COLS 7


char game_history[100][ROWS][COLS];  // �C�����v�A�̦h�x�s 100 �B��

struct Player
{
   int move;
   int pos;
   int posboard[6][2];
   char *player[6];
};

int main()
{

    //��l���A
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


    // �N��e���ѽL���A�ƻs�@���[�J�C�����v��
    memcpy(game_history[0], board, sizeof(board));

    //�����C�ӴѤl����m
    PlayGame(rplayer.player,bplayer.player,board,Pstate);


}

//minmax�t��k+�[�W�إ߹C����
void PlayGame(char *Rplayer[6],char *Bplayer[6],char board[ROWS][COLS],int Pstate)
{
    /*�W�h�P�_��

    R���a:
    1.���0-5���@���� ->�i���ʪ�
    2.��ܨ��Vr ---> ������ b---> ������
    3.���o�B�|�J�쪺���p(�ѧ�����)

    */


    if(Pstate == 0)
    {
        for(int i=0;i<6;i++)
        {
            if(*(Rplayer[i]+1)==' '){
                printf("Y �� %d\n",i);
            }
            if(*(Rplayer[i]+7)==' '){
                printf("Y �� %d\n",i);
            }
            if(*(Rplayer[i]+8)==' '){
                printf("Y �� %d\n",i);
            }

        }
    }
    else
    {



    }


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
