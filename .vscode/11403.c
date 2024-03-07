#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[101][101];
int visit[101];
void dfs(int n,int s,int c)
{
    visit[c]=1;
    for (int i=1;i<=n;i++)
    {
        if (arr[c][i])
        {
            if (!visit[i])
            {   
                dfs(n,s,i);
                arr[s][i]=1;
            }
            if (s==i)
                arr[s][i]=1;
        }
    }
}
void print(int n)
{
    for (int i=1;i<=n;i++)
    {
        for (int k=1;k<=n;k++)
            printf("%d ",arr[i][k]);
        puts("");
    }
}
int main(void)
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        for (int k=1;k<=n;k++)
            scanf("%d",&arr[i][k]);
        visit[i]=0;   
    }
    for (int i=1;i<=n;i++)
    {
        dfs(n,i,i);
        for (int j=1;j<=n;j++)
            visit[j]=0;
    }
    print(n);
    return 0;
}