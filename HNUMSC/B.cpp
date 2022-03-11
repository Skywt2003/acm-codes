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

int n;
int a[maxn],f[maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=f[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=0;j<i-1;j++)
			f[i]=std::max(f[i],f[j]+a[i]);

	int ans=0;
	for (int i=1;i<=n;i++) ans=std::max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}