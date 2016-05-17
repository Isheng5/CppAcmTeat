//
// Created by zengjiean on 16-5-17.
//

#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int c40()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		int g=gcd(x,y);
		int c=x/g*y;
		cout<<g<<" "<<c<<endl;
	}
	return 0;
}