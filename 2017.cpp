//
// Created by zengjiean on 16-4-20.
//
#include<iostream>
#include<string>
using namespace std;
int acm2017()
{
    string a;
    getline(cin,a);
    int kongge=0;//空格个数
    int zimu=0;//字母数字，必须是英文字母
    int shuzi=0;//数字
    for(int i=0;i!=a.size ();i++)
    {
        if(a[i]==' ')kongge++;
        else if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))zimu++;
        else if(a[i]>='0'&&a[i]<='9')shuzi++;
    }
    cout<<zimu<<' '<<kongge<<' '<<shuzi<<endl;

    return 0;
}