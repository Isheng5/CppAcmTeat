//
// Created by zengjiean on 16-4-16.
//浙大OJ第2008道题目
//1234


#include<iostream>
#define MAX 100
using namespace std;

double N[MAX];

void coutnum(int num,int& a,int& b,int& c){
    a = 0,b = 0,c = 0;
    for (int i = 0; i < num; i++){
        if (N[i] > 0) c++;
        else if(N[i] == 0) b++;
        else a++;
    }
}

int acm2008()
{
    int n;
    while(cin >> n &&n != 0){
        int a,b,c;
        for(int i = 0;i < n;i++){
            cin >> N[i];
        }
        coutnum(n,a,b,c);
        cout << a <<" "<< b << " " << c << endl;
    }
    return 0;
}
