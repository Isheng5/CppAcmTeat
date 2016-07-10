//
// Created by zengjiean on 16-7-10.
//
#include<iostream>
#include<stack>
using namespace std;
const int MAXSOR = 5000;

struct men{
    int n;
    int num;
}sor[MAXSOR];

void StarSor(int &nn){
    for(int i=0;i < nn;i++){
        sor[i].n=1;
        sor[i].num=i+1;
    }
}

int EndSor(int &n){
    int x=0;
    for(int s=0;s < n;s++){
        if(sor[s].n==1) x++;
    }
    return x;
}

void PrintSor(int &n){
    int k=0;
    for(int i=0;i<n;i++){
        if(sor[i].n == 1) {
            k++;
            if(k==1) cout<<sor[i].num;
            else cout<<" "<<sor[i].num;
        }
//		cout<<sor[i].num<<" ";
    }
    cout<<endl;
//	getchar();
}

void text1(){
    int n;
    cin>>n;
    while(n--){
//		stack<int> s;
        int NumSor,tool=2,kk,j;
        cin>>NumSor;
        StarSor(NumSor);
        while(EndSor(NumSor) != 2){
            if(EndSor(NumSor) == 3) break;
            if(EndSor(NumSor) == 2) break;
            if(EndSor(NumSor) == 1) break;
//			if(EndSor(NumSor)<4) break;
            kk=0;
            switch(tool){
                case 2:
                    kk=0;
                    for(j=0;j<NumSor;j++){
                        if(sor[j].n==1) kk++;
                        if(kk%2==0) sor[j].n=0;
                    }
                    tool = 3;
                    break;
                case 3:
                    kk=0;
                    for(j=0;j<NumSor;j++){
                        if(sor[j].n==1) kk++;
                        if(kk%3==0) sor[j].n=0;
                    }
                    tool = 2;
                    break;
            }
//			if(EndSor(NumSor) == 3) break;
        }
//		cout<<EndSor(NumSor)<<endl;
        PrintSor(NumSor);
    }
}
