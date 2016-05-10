//
// Created by zengjiean on 16-5-10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <queue>
#include <iostream>
using namespace std;
#define MAXN 410
int n;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int grid[MAXN][MAXN];
int step[MAXN][MAXN];
bool vis[MAXN][MAXN];
int start_x, start_y;
int pos_x, pos_y;
bool flag;

int read_ch()
{
	char ch;
	while (ch = getchar())
	{
		if (ch == 'X') return 0;
		if (ch == 'O') return 1;
	}
}
void read()
{
	flag = false;
	memset(grid, '\0', sizeof(grid));
	memset(vis, false, sizeof(vis));
	scanf("%d", &n);
	scanf("%d %d %d %d", &start_x, &start_y, &pos_x, &pos_y);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			grid[i][j] = read_ch();
}

void dfs(int cnt_x, int cnt_y)
{
	if(flag)
		return ;
	if(cnt_x == pos_x && cnt_y == pos_y)
	{
		flag = true;
		return ;
	}
	for(int i = 0; i < 4; i ++)
	{
		int x = cnt_x + dir[i][0];
		int y = cnt_y + dir[i][1];
		if(x <= 0 || x > n || y <= 0 || y > n || vis[x][y] || !grid[x][y]) continue;
		vis[x][y] = true;
		dfs(x, y);
		//vis[x][y] = false;
	}
}

bool bfs(int cnt_x, int cnt_y)
{
	queue <int> Q;
	memset(vis, false, sizeof(vis));
	memset(step, 0x3f, sizeof(step));
	vis[cnt_x][cnt_y] = true;
	step[cnt_x][cnt_y] = 0;
	Q.push(cnt_x);
	Q.push(cnt_y);
	while(!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		int y = Q.front();
		Q.pop();

		if(x == pos_x && y == pos_y)
			return true;

		for(int i = 0; i < 4; i ++)
		{
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			int s = step[x][y] + 1;
			if(xx <= 0 || xx > n || yy <= 0 || yy > n || !grid[xx][yy]) continue;
			if(!vis[xx][yy])
			{
				vis[xx][yy] = true;
				if(s < step[xx][yy])
				{
					step[xx][yy] = s;
					Q.push(xx);
					Q.push(yy);
				}
			}
		}
	}
	return false;
}

int x004()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T --)
	{
		read();
		vis[start_x][start_y] = true;
		//dfs(start_x, start_y);
		//printf("%s\n", flag? "YES" : "NO");
		int ans = bfs(start_x, start_y);
		printf("%s\n", ans? "YES" : "NO");
	}
	return 0;
}
