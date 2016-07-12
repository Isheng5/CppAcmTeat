//
// Created by zengjiean on 16-4-20.
//
#include<iostream>
using namespace std;

int N2016[100];

int acm2016(){
    int n;
    while (cin >> n && n != -1){
        if(n == 0) continue;
        int min=0 ,swap;
        for(int i = 0;i < n;i++){
            cin >> N2016[i];
            if(N2016[i] < N2016[min]) min = i;
        }
        swap = N2016[min];
        N2016[min] = N2016[0];
        N2016[0] = swap;
        cout << N2016[0];
        for (int j = 1; j < n ; ++j) {
            cout <<" "<< N2016[j];
        }
        cout << endl;
    }
}
