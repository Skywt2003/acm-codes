#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=105;

int t,n;
int a[maxn];

signed main(){
	t=read();
	while (t--){
		n=read();
		int ans=0,delta=0;
		for (int i=1;i<=n;i++){
			int x=read();
			if (x > i+delta) ans+=x-(i+delta),delta+=x-(i+delta);
		}
		printf("%lld\n",ans);
	}
	return 0;
}