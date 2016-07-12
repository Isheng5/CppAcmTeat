//
// Created by zengjiean on 16-4-18.
//
#include <iostream>
using namespace std;

int Pantao[30];

void StarPantao(){
    Pantao[0] = 1;
    for (int i = 1;i < 30;i++){
        Pantao[i] = (Pantao[i-1] + 1) * 2;
    }
}

int acm2013(){
    StarPantao();
    int n;
    while(cin >> n && n != -1 ){
        cout << Pantao[n-1] << endl;
    }
    return 0;
}

