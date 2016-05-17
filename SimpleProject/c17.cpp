//
// Created by zengjiean on 16-5-17.
//

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int d[10005];
int c17()
{
    int N;
    int i,j,Max;
    char str[10005];
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str);
        Max=0;
        for(i=0;i<len;i++)
            d[i]=1;
        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len;j++)
            {
                if(str[j]>str[i]&&d[j]<d[i]+1)
                    d[j]=d[i]+1;
            }
        }
        for(i=0;i<len;i++)
        {
            if(Max<d[i])
                Max=d[i];
        }
        printf("%d\n",Max);
    }
    return 0;

}