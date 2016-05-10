//
// Created by zengjiean on 16-5-10.
//
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int x002()
{
    int T,n,ans;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    for(scanf("%d",&T);T;T--)
    {
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i*i>n) break;
            ans++;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
