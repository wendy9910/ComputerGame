#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 3
#define MAX_DEPTH 30


int goal[N][N] = {{1,2,3},{4,5,6},{7,8,0}};

int best_depth = MAX_DEPTH;
int found_solution = 0;

int main()
{
    int node[N][N] = {{2,5,0},{1,6,3},{4,7,8}};
    int origin_x=0,origin_y=0;
    int state = 0,depth=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(node[i][j]==0){
                origin_x =i;
                origin_y =j;
                break;
            }
        }
    }
    DLS(node,origin_x,origin_y,depth);

}

void DLS(int node[N][N],int mx,int my,int depth)
{
    /*
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d ",node[i][j]);
            if(j==2)printf("\n");
        }
    }
    printf("--------------\n");
    */
    if (found_solution) {
        return;
    }

    if (depth >= best_depth) {
        return;
    }

    if (memcmp(node, goal, sizeof(goal)) == 0) {
        printf("solution found with %d steps\n",depth);
        found_solution = 1;
        best_depth = depth;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("%d ",node[i][j]);
                if(j==2)printf("\n");
            }
        }

        return;
    }


    int mx1,mx2,mx3,mx4,my1,my2,my3,my4;

    mx1 = mx+1; my1 = my;
    mx2 = mx-1; my2 = my;
    mx3 = mx;   my3 = my+1;
    mx4 = mx;   my4 = my-1;

    if(mx1>=0 && my1>=0 &&  mx1 <N && my1 <N )
    {
        node[mx][my] = node[mx1][my1];
        node[mx1][my1] = 0;
        DLS(node,mx1,my1,depth+1);
        node[mx1][my1] = node[mx][my];
        node[mx][my] = 0;
    }
    if(mx3>=0 && my3>=0 &&  mx3<N && my3<N)
    {
        node[mx][my] = node[mx3][my3];
        node[mx3][my3] = 0;
        DLS(node,mx3,my3,depth+1);
        node[mx3][my3] = node[mx][my];
        node[mx][my] = 0;
    }
    if(mx2 >=0 && my2>=0 &&  mx2<N && my2<N)
    {
        node[mx][my] = node[mx2][my2];
        node[mx2][my2] = 0;
        DLS(node,mx2,my2,depth+1);
        node[mx2][my2] = node[mx][my];
        node[mx][my] = 0;
    }
    if(mx4>=0 && my4>=0 &&  mx4<N && my4<N)
    {
        node[mx][my] = node[mx4][my4];
        node[mx4][my4] = 0;
        DLS(node,mx4,my4,depth+1);
        node[mx4][my4] = node[mx][my];
        node[mx][my] = 0;
    }
}

/*int isCorrect()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            if(node[i][j] != goal[i][j]) return 0;
    }
    return 1;
}*/
