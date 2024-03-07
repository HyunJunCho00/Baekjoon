#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int arr[501][501];
int comp(int a, int b)
{
    if (a>b)
        return a;
    return b;
}
void bfs(int a,int b,int n,int m)
{
    int result=0;
    int select,select1;
    
}
int main(void)
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++)
    {
        for (int k=0;k<m;k++)
        {
            scanf("%d",&arr[i][k]);
        }
    }
    bfs(0,0,n,m);
    return 0;
}