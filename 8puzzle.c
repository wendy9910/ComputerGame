#include <stdio.h>
#include <stdlib.h>

#define N 3
#define MAX_DEPTH 100

int inti[N][N] = { {3,8,5},{0,4,2},{1,6,7} };
int goal[N][N] = { {1,2,3},{4,5,6},{7,8,0} };

int moves[MAX_DEPTH];
int best_moves[MAX_DEPTH];
int best_depth = MAX_DEPTH;

int main()
{
    printf("8-Puzzle\n");
    int origin_x,origin_y;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(inti[i][j]==0){
                origin_x=i;
                origin_y=j;
                break;
            }
        }
    }

    search_DFS(origin_x,origin_y,0,-1,-1);

    for(int i=0;i<best_depth;i++) printf("move[%d]=%d\n",i,best_moves[i]);

    return 0;
}

int isCorrect(){

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            if(inti[i][j] != goal[i][j]) return 0;
    }
    return 1;
}


void search_DFS(int zero_x,int zero_y,int depth,int px,int py)
{
    if(depth >= MAX_DEPTH) return;

    if(depth != 0) moves[depth-1] = inti[px][py];

    if(isCorrect()==1){
        printf("solution found with %d steps\n",depth);

        best_depth = depth;

        for(int i=0;i<depth;i++) best_moves[i] = moves[i];

        return;
    }

    int x1,y1,x2,y2,x3,y3,x4,y4;

    //位移四個方向
    //到時候減少參數
    x1 = zero_x+1;
    y1 = zero_y;

    x2 = zero_x-1;
    y2 = zero_y;

    x3 = zero_x;
    y3 = zero_y+1;

    x4 = zero_x;
    y4 = zero_y-1;

    if(x1==px &&y1==py) x1=y1=-1;
    if(x2==px &&y2==py) x2=y2=-1;
    if(x3==px &&y3==py) x3=y3=-1;
    if(x4==px &&y4==py) x4=y4=-1;

    if(x1>=0 && y1>=0 && x1<N && y1<N){
        inti[zero_x][zero_y] = inti[x1][y1];
        inti[x1][y1] = 0;
        search_DFS(x1,y1,depth+1,zero_x,zero_y);
        inti[x1][y1] = inti[zero_x][zero_y];
        inti[zero_x][zero_y] = 0;
    }
    if(x2>=0 && y2>=0 && x2<N && y2<N){
        inti[zero_x][zero_y] = inti[x2][y2];
        inti[x2][y2] = 0;
        search_DFS(x2,y2,depth+1,zero_x,zero_y);
        inti[x2][y2] = inti[zero_x][zero_y];
        inti[zero_x][zero_y] = 0;
    }
    if(x3>=0 && y3>=0 && x3<N && y3<N){
        inti[zero_x][zero_y] = inti[x3][y3];
        inti[x3][y3] = 0;
        search_DFS(x2,y2,depth+1,zero_x,zero_y);
        inti[x3][y3] = inti[zero_x][zero_y];
        inti[zero_x][zero_y] = 0;
    }
    if(x4>=0 && y4>=0 && x4<N && y4<N){
        inti[zero_x][zero_y] = inti[x4][y4];
        inti[x4][y4] = 0;
        search_DFS(x4,y4,depth+1,zero_x,zero_y);
        inti[x4][y4] = inti[zero_x][zero_y];
        inti[zero_x][zero_y] = 0;
    }


}



/*
int at[9] = {2,8,3,1,0,4,7,6,5};
int af[9] = {1,2,3,8,0,4,7,6,5};

int main()
{
    int r,c,m=0,i=4,n=1;


    while(n!=0)
    {
        c = i % 3;
        r = i / 3;

        if(c != 0) //move left
        {
            swap(at,-1,i);
            n = checkSort(at,af);

        }
        if(c != 2) //move right
        {
            swap(at,1,i);
            n = checkSort(at,af);
        }
        if(r != 0) //move up
        {
            swap(at,3,i);
            n = checkSort(at,af);
        }
        if(r != 2) //move down
        {
            swap(at,-3,i);
            n = checkSort(at,af);
        }
        for(int k=0;k<9;k++)
        {
            printf("%d ",at[k]);
        }
        printf("\n");

    }

}

int swap(int a[],int s,int i)
{
    int temp;
    temp = a[i];
    a[i]=a[i+s];
    a[i+s]=temp;
}
int checkSort(int a1[],int a2[])
{
    for(int k=0;k<9;k++)
    {
        if(a1[k]!=a2[k])
            return 0;
    }
    return 1;
}
*/
