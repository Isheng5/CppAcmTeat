//
// Created by zengjiean on 16-5-17.
//
#include <stdio.h>
#include <string.h>
int c74()
{
    int a,b;
    int a1,a2,a3,b1,b2,b3;
    while(scanf("%d%d",&a,&b)&&(a||b))
    {
        int cnt=0;
        a1=a/100;
        a2=a/10%10;
        a3=a%10;
        b1=b/100;
        b2=b/10%10;
        b3=b%10;
        if(a3+b3>=10)
        {
            cnt++;
            a2++;
        }
        if(a2+b2>=10)
        {
            cnt++;
            a1++;
        }
        if(a1+b1>=10)
        {
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
