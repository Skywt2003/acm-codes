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

const int maxn=505;
const int INF=0x3f3f3f3f;

int n,r,m;
int d[maxn],v[maxn];
int f[maxn][maxn];

signed main(){
	n=read()-1,r=read(),m=read();
	for (int i=0;i<=n;i++) d[i]=read();
	for (int i=0;i<=n;i++) v[i]=read();

	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=n;i++) f[i][0]=f[i-1][0] + v[i-1]*(d[i]-d[i-1]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			for (int k=0;k<i;k++) if (j-(i-k-1)>=0 && f[k][j-(i-k-1)]!=INF){
				f[i][j]=std::min(f[i][j], f[k][j-(i-k-1)] + v[k]*(d[i]-d[k]));
				// printf("Adjust f[%d][%d]: %d\n",i,j,f[i][j]);
			}
	int ans=INF;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m-(n-i);j++)
			ans = std::min(ans, f[i][j] + v[i]*(r-d[i]));
	printf("%d\n",ans);
	return 0;
}