#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
const int N=1e5;
const int tt=998244353;
const int INF=1LL<<60;

int t,n;
int a[maxn];
int f[2][maxn];

signed main(){
	t=read();
	while (t--){
		for (int i=1;i<=N;i++) f[0][i]=f[1][i]=INF;
		
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) f[n&1][a[n]]=0;

		for (int i=n-1;i>=1;i--){
			// memset(f[i&1],INF,sizeof(f[i&1]));
			for (int j=1;j<=sqrt(a[i]);j++) f[i&1][a[i]/j]=f[i&1][a[i]/(a[i]/j)]=INF;
			// 没法清数组
			f[i&1][a[i]]=0;
			for (int j=1;j<=sqrt(a[i+1]);j++){
				int x=a[i+1]/j; // 此处向下取整即可！
				if (f[1-(i&1)][x]!=INF){
					int k=(a[i]+x-1)/x; // 这里要向上取整
					f[i&1][k] = (f[i&1][k] + f[1-(i&1)][x] + (n-i+1)*(x-1))%tt;
				}
				int x=(a[i+1])/(a[i+1]/j);
				if (x!=a[i+1]/j && f[1-(i&1)][x]!=INF){
					int k=(a[i]+x-1)/x;
					f[i&1][k] = (f[i&1][k] + f[1-(i&1)][x] + (n-i+1)*(x-1))%tt;
				}
			}
		}
		int ans=0;
		for (int i=1;i<=a[1];i++) ans=(ans+f[1][i])%tt;
		printf("%lld\n",ans);
	}
	return 0;
}