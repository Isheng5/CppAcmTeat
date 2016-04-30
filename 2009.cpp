//
// Created by zengjiean on 16-4-16.
//
#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double m2009[1000];

void cal2009(double n,int m,double& sum){
    for (int i = 0; i < m - 1; i++) {
        double cal;
        cal = sqrt(m2009[i]);
        m2009[i+1] = cal;
        sum = sum + m2009[i+1];
    }
}

int acm2009(){
    int k=2;
    double n=0;
    int m=0;
    while (cin >> n >> m && n!= EOF&&m!=EOF){
        double sum = n;
        m2009[0] = n;
        cal2009(n,m,sum);
        cout<<setiosflags(ios::fixed);
        cout.precision(2);
        cout << sum << endl;
        k--;
    }
}

