//
// Created by zengjiean on 16-4-16.
//
#include <iostream>
#include <cmath>
using namespace std;

int m2009[40];

void cal2009(){
    m2009[0]=1;
    m2009[1]=2;
    m2009[2]=3;
    for (int i = 3; i < 40; i++) {
        m2009[i] = m2009[i-1]+m2009[i-2]+m2009[i-3];
    }
}

int acm2009(){
    int n=0;
    while (cin >> n && n!= EOF){
        cal2009();
        cout << m2009[n-1] << endl;
    }
}

