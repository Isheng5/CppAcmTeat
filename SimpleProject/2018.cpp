//
// Created by zengjiean on 16-5-5.
//
#include<iostream>

int N1[200];

void Star(){
    int i,j=1;
    N1[0]=1,N1[1]=2;N1[2]=3;N1[3]=4;
    for(i=4;i<200;i++){
        N1[i]=N1[i-1]+N1[i-4];
    }
}

using namespace std;
int acm2018()
{
    int n;
    Star();
    while(cin >> n && n != 0){
        cout << N1[n-1]<<endl;
    }

    return 0;
}
