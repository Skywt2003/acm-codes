#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e3+5;

int t,n,H;
int a[maxn];

signed main(){
	t=read();
	while (t--){
		n=read();H=read();
		for (int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+1+n);
		int ans=H/(a[n]+a[n-1])*2;
		H%=(a[n]+a[n-1]);
		if (H>a[n]) ans+=2; else
		if (H>0) ans+=1;
		printf("%lld\n",ans);
	}
	return 0;
}