#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int x,y,z;
    int day;
}que;
que q[101*101*101*2];
int arr[101][101][101];
int visit[101][101][101];
int coor[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int front=0,rear=0;
void bfs(int m,int n,int h,int count,int min,int max)
{
    int count1=0,result=0,cnt=0;
    while (front<rear)
    {
        int cnt=rear;
        int count2=count1;
        result++;
        for (int k=front;k<cnt;k++)
        {
            int x=q[k].x,y=q[k].y,z=q[k].z;
            for (int i=0;i<6;i++)
            {
                int x1=x+coor[i][0],y1=y+coor[i][1],z1=z+coor[i][2];
                if ((x1<h&&x1>=0)&&(y1<m&&y1>=0)&&(z1<n&&z1>=0)&&!visit[x1][y1][z1])
                {
                    if (!arr[x1][y1][z1]&&arr[x][y][z]!=-1)
                    {
                        arr[x1][y1][z1]=1;
                        q[rear].day=result;
                        q[rear].x=x1;q[rear].y=y1;q[rear++].z=z1;
                        count1++;
                    }
                    visit[x1][y1][z1]=1;
                }
            }
        }
        if (count==count1)
            break;
        front=cnt;
    }
    if (count==count1)
    {
        printf("%d\n",q[rear-1].day);
    }
    else
    {
        printf("%d\n",-1);
    }
}
int main(void)
{
    int n,m,h;
    scanf("%d %d %d",&m,&n,&h);
    int s,s1,s2,count=0,count1=0,count2=0;
    getchar();
    for (int i=0;i<h;i++)
    {
        for (int k=0;k<m;k++)
        {
            for (int l=0;l<n;l++)
            {
                scanf("%d",&arr[i][k][l]);
                if (arr[i][k][l]==1)
                {
                    s=i;s1=k;s2=l;
                    count2++;
                    q[rear].x=s;q[rear].y=s1;q[rear++].z=s2;
                }
                if (!arr[i][k][l])
                    count++;
                if (arr[i][k][l]==-1)
                    count1++;
            }
        }
    }
    visit[q[front].x][q[front].y][q[front].z]=1;
    if (!count)
        printf("0\n");
    else
        bfs(m,n,h,count,count1,count2);
    return 0;
}