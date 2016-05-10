//
// Created by zengjiean on 16-5-10.
//
#include<iostream>
using namespace std;
long long int H[1001];
void init(){
    H[0]=1;
    for(int i=1;i<1001;i++){
        H[i]=((4*i-2)*H[i-1]/(i+1))%1000000007;
    }
}
int x005(){
    int n;
    init();
    while(cin>>n){
        cout<<H[n]<<endl;
    }
return 0;
}
