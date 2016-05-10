//
// Created by zengjiean on 16-5-10.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int x006()
{
    //freopen("in.txt","r",stdin);
    //freopen("outsample.txt","w",stdout);
    int t;
    scanf("%d",&t);
    char x;
    int y;
    int cas=1;
    while(t--)
    {
        getchar();
        scanf("%c,%d",&x,&y);
        printf("Case:%d ",cas++ );
        if(x>='a' && x<='z') printf("%d\n",0-(x-'a'+1)+y);
        else printf("%d\n",x-'A'+1+y);
    }
    return 0;
}
