#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <cmath>
#define LOCAL
using namespace std;

typedef long long ll;
const ll MOD = 1E9 + 7;

int add(int x, int y) { return (x + y < MOD)?(x + y):(x + y - MOD); }
int mul(int x, int y) { return 1ll * x * y % MOD; }

int main(){
    #ifdef LOCAL
        freopen("A-large-practice.in","r",stdin);
        freopen("A.out","w",stdout);
    #endif
    int T, R, C;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        scanf("%d%d",&R, &C);
        if(R < C) swap(R,C);
        int C2 = mul(C, C);
        int C3 = mul(C2, C);
        int C4 = mul(C2, C2);
        int res = add(C2, -C4);
        res = (res + mul(mul(2, R), C3))%MOD;
        res = (res - mul(mul(2, R), C))%MOD;
        res = (res*(MOD+1)/12)%MOD;
        res = (res + MOD) % MOD;
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}
