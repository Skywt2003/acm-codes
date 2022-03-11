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

const int maxn=10005;
const int INF=1<<30;

int n,a[maxn];
int f[maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),f[i]=INF;
	f[1]=0;
	for (int i=1;i<=n;i++) if (f[i]!=INF)
		for (int j=i+1;j<=std::min(i+a[i],n);j++)
			f[j]=std::min(f[j],f[i]+1);
	printf("%d\n",f[n]);
	return 0;
}