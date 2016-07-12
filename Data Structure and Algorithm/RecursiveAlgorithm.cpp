//recursive algorithm --- 递归算法的拼音
// Created by zengjiean on 2016/7/12 0012.
//
#include <iostream>
#include <cmath>
#define Case cAckermanns
using namespace std;
//-----------------------------
//       编写递归
//-----------------------------
//
int cgcd(int x,int y){
    return y == 0 ? x : cgcd(y, x % y);
}

int Ackermanns(int i,int j){//阿克曼函数
    if(1 == i) return pow(2, j);
    return 1 == j ? Ackermanns(i - 1, 2) : Ackermanns(i - 1, Ackermanns(i, j - 1));
}

void cAckermanns(){
    int m,n;
    while(cin>>m>>n){
        cout << cgcd(m,n) << endl;
    }
}

int ConRecursive(int n){//递归函数的实现，使用
    return n % 2 == 0 ? n/2 : ConRecursive(3 * n +1);
}

void cConRecursive(){
    int n;
    while(cin>>n){
        cout << ConRecursive(n) << endl;
    }
}

int Fibonacci(int n){//斐波那契递归函数
    return n == 1 || n == 2 ? n : Fibonacci(n - 2) + Fibonacci(n - 1);
}

void CFibonacci(){
    int n;
    while(cin>>n){
        cout << Fibonacci(n) << endl;
    }
}

int NoRecursive(){
    int n,sum=1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        sum *= (i+1);
    }
    cout << sum << endl;
    return 0;
}

int Recursive(){
    Case();
}