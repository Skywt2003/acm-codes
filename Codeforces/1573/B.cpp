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

const int maxn=1e5+5;
const int INF=(int)1<<60;

int t;
int n;
int a[maxn],b[maxn];
int posa[maxn*2],posb[maxn*2];
int ans;

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read(),posa[a[i]]=i;
		for (int i=1;i<=n;i++) b[i]=read(),posb[b[i]]=i;

		ans=INF;
		int lst=n;
		for (int i=2*n-1;i>=1;i-=2){
			lst=min(lst,posb[i+1]);
			ans=min(ans,(posa[i]-1)+(lst-1));
		}

		printf("%lld\n",ans);
	}
	return 0;
}