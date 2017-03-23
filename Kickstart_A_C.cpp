/* 二分。cover()判断是否为解。*/

#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#define LOCAL
typedef long long ll;
using namespace std;

const int MAXN = 2010;

int g[MAXN][4];
int N;

bool cover(int xs, int xe, int ys, int ye, int zs, int ze){

    int minx, miny, minz, maxx, maxy, maxz;
    minx = miny = minz = 2E8 + 100;
    maxx = maxy = maxz = -2E8 - 100;
    for(int i = 0; i < N; ++i){
        if(
           g[i][0] - g[i][3] >= xs
           && g[i][0] + g[i][3] <= xe
           && g[i][1] - g[i][3] >= ys
           && g[i][1] + g[i][3] <= ye
           && g[i][2] - g[i][3] >= zs
           && g[i][2] + g[i][3] <= ze
          );
        else{
            minx = min(minx, g[i][0] - g[i][3]);
            maxx = max(maxx, g[i][0] + g[i][3]);
            miny = min(miny, g[i][1] - g[i][3]);
            maxy = max(maxy, g[i][1] + g[i][3]);
            minz = min(minz, g[i][2] - g[i][3]);
            maxz = max(maxz, g[i][2] + g[i][3]);
        }
    }
    int r = xe - xs;
    if(maxx - minx <= r && maxy - miny <= r && maxz - minz <= r) return true;
    return false;
}


int main(){
    #ifdef LOCAL
        freopen("C-large-practice.in","r",stdin);
        freopen("C.out","w",stdout);
    #endif
    int T, minx, maxx, miny, maxy, minz, maxz;

    scanf("%d",&T);
    for(int tt = 1;tt <= T;++tt){
        scanf("%d", &N);
        minx = miny = minz = 2E8 + 100;
        maxx = maxy = maxz = -2E8 - 100;
        for(int n = 0;n < N;++n){
            scanf("%d%d%d%d", &g[n][0], &g[n][1], &g[n][2], &g[n][3]);
            minx = min(minx, g[n][0] - g[n][3]);
            maxx = max(maxx, g[n][0] + g[n][3]);
            miny = min(miny, g[n][1] - g[n][3]);
            maxy = max(maxy, g[n][1] + g[n][3]);
            minz = min(minz, g[n][2] - g[n][3]);
            maxz = max(maxz, g[n][2] + g[n][3]);
        }
        int rs, re, r;
        rs = 0; re = 4E8 + 100;
        while(rs < re){
            r = (rs + re)/2;
            if(
               cover(minx, minx+r, miny, miny+r, minz, minz+r)
               || cover(minx, minx+r, miny, miny+r, maxz-r, maxz)
               || cover(minx, minx+r, maxy-r, maxy, minz, minz+r)
               || cover(minx, minx+r, maxy-r, maxy, maxz-r, maxz)
               || cover(maxx-r, maxx, miny, miny+r, minz, minz+r)
               || cover(maxx-r, maxx, miny, miny+r, maxz-r, maxz)
               || cover(maxx-r, maxx, maxy-r, maxy, minz, minz+r)
               || cover(maxx-r, maxx, maxy-r, maxy, maxz-r, maxz)
              ) re = r;
            else
                rs = r + 1;
        }
        printf("Case #%d: %d\n", tt, re);
    }
    return 0;
}
