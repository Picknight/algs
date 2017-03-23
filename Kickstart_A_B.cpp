/* 将 * 扩展为四个任意字符。经典字符串动态规划。*/

#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#define LOCAL
using namespace std;

const int MAXN = 8E3 + 10;

char s1[MAXN], s2[MAXN];
char in[MAXN];
bool vs[MAXN][MAXN];
void debug(){

}

int getStr(char s[]){

    scanf("%s", in);
    int n = 0;
    for(int i = 0;in[i];++i){
        if(in[i] == '*'){
            s[++n] = 0;
            s[++n] = 0;
            s[++n] = 0;
            s[++n] = 0;
        }
        else
            s[++n] = in[i];
    }
    return n;
}


int main(){
    #ifdef LOCAL
        freopen("B-large-practice.in","r",stdin);
        freopen("B.out","w",stdout);
    #endif
    int T;
    scanf("%d",&T);
    for(int tt = 1;tt <= T;++tt){

        int n = getStr(s1);
        int m = getStr(s2);
        memset(vs, 0, MAXN * MAXN);
        vs[0][0] = true;
        for(int i = 0;i<=n;++i)
            for(int j = 0;j<=m;j++){
                if(vs[i][j]){
                    vs[i][j + 1] |= s2[j + 1] == 0;
                    vs[i + 1][j] |= s1[i + 1] == 0;
                    vs[i + 1][j + 1] |= !s1[i + 1] || !s2[j + 1] || s1[i + 1] == s2[j + 1];
                }
            }
        printf("Case #%d: ",tt);
        puts(vs[n][m] ? "TRUE" : "FALSE");



    }
    return 0;
}
