//
// Created by zengjiean on 16-4-19.
//
#include <iostream>
#include<iomanip>
using namespace std;

int Cout2[100];

int acm2014(){
    int m ;
    while(cin >> m && m != EOF){
        double coutsum = 0,ss;
        double max2014 = -1,min2014 = 101;
        for(int i=0;i < m;i++){
            cin >> ss ;
            if(ss > max2014) max2014 = ss;
            if(ss < min2014) min2014 = ss;
            coutsum = coutsum + ss;
        }
        cout<<setiosflags(ios::fixed);
        cout.precision(2);
        cout << (coutsum - max2014 -min2014)/(m-2) << endl;
    }
    return 0;
}
