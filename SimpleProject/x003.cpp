//
// Created by zengjiean on 16-5-10.
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int N = 10;
const int inf = 2147483647;
int s[N];
int x003()
{
    //freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n,i,x,m;
    while(~scanf("%d",&n))
    {
        memset(s,0,sizeof(s));
        m=10;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            s[x]++;
            if(x%2 && x<m)
                m=x;
        }
        if(m==10 || ( s[0]==n-1 && s[0]!=0) )
        {
            puts("-1");
            continue;
        }
        s[m]--;
        for(i=9;i>=0;i--)
            while(s[i]--)
                printf("%d",i);
        printf("%d\n",m);
    }
    return 0;
}
