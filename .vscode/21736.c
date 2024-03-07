#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int x,y;
}que;
que q[600*600];
int arr[601][601];
int visit[601][601];
int front=0,rear=0;
int coor[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
void push(int x,int y)
{
    q[rear].x=x;q[rear++].y=y;
}
int pop()
{
    return q[front].x;
}
int pop1()
{
    return q[front++].y;
}
void bfs(int a,int b,int n,int m)
{
    visit[a][b]=1;
    push(a,b);
    int count=0;
    while (front<rear)
    {
        int x=pop(),y=pop1();
        for (int i=0;i<4;i++)
        {
            int x1=coor[i][0]+x,y1=coor[i][1]+y;
            if (arr[x1][y1]==-1)
                visit[x1][y1]=1;
            else{
                if ((x1>=0&&x1<n)&&(y1>=0&&y1<m)&&!visit[x1][y1])
                {
                    if (arr[x1][y1])
                        count++;
                    visit[x1][y1]=1;
                    push(x1,y1);  
                }
            }
        }
    }
    if (!count)
        printf("TT\n");
    else
        printf("%d\n",count);
}
int main(void)
{
    int n,m;
    char ff[601];
    scanf("%d %d",&n,&m);
    getchar();
    int a,b;
    for (int i=0;i<n;i++)
    {
        scanf("%s",ff);getchar();
        for (int k=0;k<m;k++)
        {
           if (ff[k]=='O')
           {
                arr[i][k]=0;
           }
           else if (ff[k]=='P')
           {
                arr[i][k]=1;
           }
           else if (ff[k]=='X')
           {
                arr[i][k]=-1;
           }
           else{
                a=i;b=k;
           }
           visit[i][k]=0;
        }
    }
    bfs(a,b,n,m);
    return 0;
}