//
// Created by zengjiean on 16-5-10.
//
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define eps 1e-6
#define MAXN 1010
#define MAXM 27
#define MAXZ 1000007


//num为f[i]为奇数的个数, num_id是 f[i]为奇数的i
int n7, num, num_id;
//f[i] 是字符i + 'a' 的个数
int f[MAXN];
char str[MAXN];
//fac[i] = i!
//fac[i] 是 fac[i]的逆
//sum为所有f[i]的和
// ans = n! / (f[1]! * f[2]! * ... * f[k]!)
//f[i] /= 2
//只取一半即可 另一半对称
LL fac[MAXN], fack[MAXN], sum;
LL euler[MAXZ];
void e_init(){
     euler[1]=1;
     for(int i=2;i<MAXZ;i++)
       euler[i]=i;
     for(int i=2;i<MAXZ;i++)
        if(euler[i]==i)
           for(int j=i;j<MAXZ;j+=i)
              euler[j]=euler[j]/i*(i-1);//先进行除法是为了防止中间数据的溢出
}


LL qpow(LL x, LL k)
{
	LL res = 1;
	while(k)
	{
		if(k & 1) res = res * x % MOD;
		x = x * x % MOD;
		k >>= 1;
	}
	return res;
}

LL inv(LL a, LL x)
{
	return qpow(a, x - 2);
}
void init2()
{
	fac[0] = fac[1] = 1;
	fack[0] = fack[1] = 1;
	for(int i = 2; i < MAXN; i ++)
	{
		fac[i] = (fac[i - 1] * i) % MOD;
		fack[i] = inv(fac[i], MOD);
	}
}
void read2()
{
	num = 0;
	num_id = 0;
	sum = 0;
	memset(f, 0, sizeof(f));
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len; i ++)
		f[str[i] - 'a'] ++;

	for(int i = 0; i < MAXM; i ++)
	{
		if(f[i] % 2)
		{
			num ++;
			num_id = i;
		}
		sum += f[i];
	}
}
void solve()
{
	if(num > 1) printf("0\n");
	else
	{
		LL ans = 1;
		if(num)
		{
			sum -= 1;
			f[num_id] -= 1;
		}
		sum /= 2;
		ans = fac[sum];
		ans %= MOD;
		for(int i = 0; i < MAXM; i ++)
			if (f[i])
			{
				ans  = (ans * fack[f[i] / 2]) % MOD;
			}
		printf("%lld\n", euler[ans % MAXZ]);
	}
}

int x007()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	init2();
	e_init();
	int T;
	scanf("%d", &T);
	while(T --)
	{
		read2();
		solve();
	}
	return 0;
}
