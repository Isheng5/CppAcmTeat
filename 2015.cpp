//
// Created by zengjiean on 16-4-19.
//
#include<iostream>
using namespace std;

int acm2015(){
    int n,m;
    int a[101];
    while(EOF != scanf("%d %d", &n, &m)){
        //if(n<m||n>100||n<=0||m<=0)    return 0;
        if(n<=100){
            a[0]=0;
            int count=0;
            int sum=0; //注意a[0],count,sum的初值都要设为0
            for(int i=1;i<=n;i++){  //这里i<=n
                a[i]=a[i-1]+2;
                count++;
                sum=sum+a[i];
                if(count==m){
                    printf("%d",sum/m);
                    count=0;
                    sum=0;
                    if(i<n)
                        printf(" ");
                }

            }
            if(count>0&&count<m)
                printf("%d\n",sum/count);
            else
                printf("\n");
        }
    }
    return 0;
}