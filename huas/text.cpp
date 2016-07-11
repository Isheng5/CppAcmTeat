//暑假算法竞赛  E-Rails
// Created by zengjiean on 16-7-11.
//通过测试，但未清晰
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

const int MAXN = 1000 + 10;

int nst,target[MAXN],nsx;

int text(){
    int nest_n=1;
    scanf("%d", &nst);
    while(1) {
        if(nst == 0) break;
        nsx = 1;
        while (nsx == 1) {
            stack<int> s;
            int A = 1, B = 1;
            for (int i = 1; i <= nst; i++) {
                scanf("%d", &target[i]);
                if(i == 1 && target[i] == 0) {nsx = 0;break;}
            }
            if(nsx == 0) break;
            int ok = 1;
            while (B <= nst) {
                if (A == target[B]) {
                    A++;
                    B++;
                }
                else if (!s.empty() && s.top() == target[B]) {
                    s.pop();
                    B++;
                }
                else if (A <= nst) {s.push(A++);}
                else {
                    ok = 0;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
        printf("\n");
        scanf("%d", &nst);

        if(nst == 0) break;

    }
    return 0;
}

