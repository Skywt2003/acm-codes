#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=100005;

int n,a[maxn];
int lft[maxn],rgt[maxn];
int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	lft[1]=rgt[n]=1;
	for (int i=2;i<=n;i++) lft[i]=(a[i]>a[i-1])?(lft[i-1]+1):1;
	for (int i=n-1;i>=1;i--) rgt[i]=(a[i]<a[i+1])?(rgt[i+1]+1):1;
	for (int i=1;i<=n;i++) ans=max(ans,1+((a[i-1]+1<a[i+1])?(lft[i-1]+rgt[i+1]):(max(lft[i-1],rgt[i+1]))));
	printf("%lld\n",ans);
	return 0;
}