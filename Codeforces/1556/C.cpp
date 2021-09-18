#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005;
const int INF=(int)1<<60;

int n;
int a[maxn];
int depth[maxn],cnt=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int ans=0,lft=0;
	for (int i=1;i<=n;i++) if (i&1) lft+=a[i]; else {
		ans+=min(lft,a[i]);
		lft-=a[i];
		while (cnt > 0 && depth[cnt] > lft) ans++,cnt--;
		int now=cnt; while (now > 0 && depth[now]==lft) ans++,now--;
		if (lft<0) lft=0; else depth[++cnt]=lft;
	}
	printf("%lld\n",ans);
	return 0;
}