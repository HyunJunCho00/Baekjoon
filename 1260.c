#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1010
#define TRUE 1
#define FALSE 0
int visited[MAX];
int arr[MAX][MAX];
void init(int n)
{
	for (int i = 1; i <= n; i++)
		visited[i] = FALSE;
}
void graphinit(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = FALSE;
		}
	}
}
void dfs(int v,int N)
{
	visited[v] = TRUE;
	printf("%d ", v);
	for (int i =1; i <=N; i++)
	{
		if (arr[v][i] == 1 && !visited[i])
			dfs(i, N);
	}
}
int queue[MAX];
int front = -1, rear = -1;
void addq(int v)
{
	queue[++rear] = v;
}
int deleteq()
{
	return queue[++front];
}
void bfs(int v, int N)
{

	printf("%d ", v);
	visited[v] = TRUE;
	addq(v);
	while (front < rear)
	{
		int pop = deleteq();
		for (int i = 1; i <= N; i++)
		{
			if (arr[pop][i] == 1 && !visited[i])
			{
				printf("%d ", i);
				addq(i);
				visited[i] = TRUE;
			}
		}
	}
}
int main(void)
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	int a, b;
	init(n);
	graphinit(n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		arr[a][b] = TRUE;
		arr[b][a] = TRUE;
	}
	dfs(v,n);
	puts("");
	init(n);
	bfs(v,n);
	return 0;
}