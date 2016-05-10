//
// Created by zengjiean on 16-5-10.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int x001()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a, b;
    //int t;
    //scanf("%d", &t);
    //while(t--)
    while(scanf("%d%d", &a, &b)==2&&b != 0)
    {
        //int a, b;
        int x, y;
        //scanf("%d%d", &a, &b);
        //if(b == 0)
        //    break;
        x = a%b;
        y = (a%b+b)%b;
        printf("%d %d\n", x, y);
    }

    return 0;
}
