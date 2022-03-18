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
int n,m;
int a[maxn];

signed main(){
	t=read();
	while (t--){
		n=read(),m=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int ans=0;
		for (int i=0;i<m;i++){
			int cnt=0;
			for (int j=1;j<=n;j++) cnt+=(bool)(a[j]&(1<<i));
			if (cnt > (n-cnt)) ans+=(1<<i);
		}
		printf("%d\n",ans);
	}
	return 0;
}