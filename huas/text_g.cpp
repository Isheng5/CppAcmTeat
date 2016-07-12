//使用DFS搜索，在书本6.4.1节中
// Created by zengjiean on 16-7-12.
//理解了DFS搜索算法，以及理解递归在DFS中的应用，妈的智障题目，磨了老子一个半小时。
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int g_maxn = 100+5;

class G_Dfs{
public:
    int m,n,cnt;
    char pic[g_maxn][g_maxn];
    bool idx[g_maxn][g_maxn];
    G_Dfs(int x,int y);
    void G_Dfs_Star();
    void G_Dfs_Set();
    void G_Dfs_mn(int x,int y);
    void dfs(int x,int y);
};

G_Dfs::G_Dfs(int x, int y) {
    n = x;
    m = y;
    cnt = 0;
    G_Dfs_Star();
}

void G_Dfs::G_Dfs_Star() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            idx[i][j] = false;
        }
    }
}

void G_Dfs::G_Dfs_Set() {
    for (int i = 1; i < n + 2; ++i) {
        for (int j = 1; j < m + 2; ++j) {
            if(i == n + 1 || j == m+1) {
                pic[i][j] = '*';
                idx[i][j] = false;
                continue;
            }
            cin >> pic[i][j];
            if(pic[i][j] == '@') idx[i][j] = true;
        }
    }
}

void G_Dfs::dfs(int x, int y) {
    if(pic[x][y] != '@' || !idx[x][y]) return;
    idx[x][y] = false;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if(i != 0 || j != 0) dfs(x+i,y+j);
        }
    }
}

void G_Dfs::G_Dfs_mn(int x,int y) {
    n = x;
    m = y;
    cnt = 0;
    G_Dfs_Star();
}


G_Dfs text(g_maxn-5,g_maxn-5);

int text_g(){
    int x,y;
    while(scanf("%d%d",&x,&y) == 2 && x && y){
        text.G_Dfs_mn(x,y);
        text.G_Dfs_Set();
        for (int i = 1; i <= text.n; i++) {
            for (int j = 1; j <= text.m; j++) {
                if(text.idx[i][j]) {text.dfs(i,j);text.cnt++;}
            }
        }
        cout << text.cnt <<endl;
    }
    return 0;
}













