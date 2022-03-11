#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;

int t;
int l,r,k;

signed main(){
	t=read();
	while (t--){
		l=read(),r=read(),k=read();
		if (l==r) {printf((l!=1)?"YES\n":"NO\n");continue;}
		bool ans=false;
		if ((l&1) && (r&1)) ans = (r-l+2)/2 <= k;
		else ans = (r-l+1)/2 <= k;
		printf(ans?"YES\n":"NO\n");
	}
	return 0;
}