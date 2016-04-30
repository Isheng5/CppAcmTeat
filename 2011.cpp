//
// Created by zengjiean on 16-4-17.
//
#include <iostream>
#include<iomanip>
using namespace std;

double Num[1000];

void StarNum(){
    for(int i=0;i< 1000;i++){
        double k = i;
        if(i % 2 == 0) Num[i] = 1.0/(k+1.0);
        else Num[i] = 0-(1.0/(k+1));
    }
}

void cal2011(int n,double& num){
    for(int j = 0;j < n;j++)
        num = Num[j] + num;
}

int acm2011(){
    int m;
    StarNum();
    cin >> m;
 //   cout << Num[2];
    for(int i=0;i<m;i++){
        int n;
        cin >> n;
        double num = 0.0;
        cal2011(n,num);
        cout<<setiosflags(ios::fixed);
        cout.precision(2);
        cout << num << endl;
    }
}
