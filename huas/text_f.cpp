//F - 简单计算器
// Created by zengjiean on 16-7-11.
//这个倒霉鬼题目，，晕死了 晕死了
//atof() 转换str威float
#include <cstdio>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int text_f()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    string s;
    bool flag;
    while(getline(cin,s))
    {
        if(s.size()==1)break;
        flag=1;//numric
        stringstream ss(s);
        double num;
        char op='#';
        stack<char> sop;
        stack<double> snum;
        while(!sop.empty())sop.pop();
        while(!snum.empty())snum.pop();
        while(1)
        {
            if(flag)
            {
                ss>>num;
                if(op=='*'||op=='/')
                {
                    double num1=snum.top();
                    snum.pop();
                    if(op=='*')num1=num*num1;
                    else num1=num1/num;
                    snum.push(num1);
                }
                else snum.push(num);
                flag=0;
            }
            else
            {
                if(ss>>op);
                else break;
                if(op=='+'||op=='-')
                {
                    double num1,num2;
                    char c;
                    if(!sop.empty())
                    {
                        c=sop.top(),sop.pop();
                        num2=snum.top(),snum.pop();
                        num1=snum.top(),snum.pop();
                        if(c=='+')num1+=num2;
                        else num1-=num2;
                        snum.push(num1);
                    }
                    sop.push(op);
                }
                flag=1;
            }
        }
        while(!sop.empty())
        {
            op=sop.top(),sop.pop();
            double num1,num2;
            num2=snum.top(),snum.pop();
            num1=snum.top(),snum.pop();
            if(op=='+')num1+=num2;
            else num1-=num2;
            snum.push(num1);
        }
        printf("%.2lf\n",snum.top());
    }
    return 0;
}