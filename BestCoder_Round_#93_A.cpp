#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
set<int> s;
int main(){
	int T, n, x;
	scanf("%d", &T);
	while(T--){
		s.clear();
		int ans = 1;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			if(!s.insert(x).nd){
				ans++;
				s.clear();
				s.insert(x);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
