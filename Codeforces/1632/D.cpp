#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5;

int n,a[maxn];
int rr[maxn];

const int STT=18; // sparse table top
int g[maxn][20];

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

void build_ST(){
	for (int i=1;i<=n;i++) g[i][0]=a[i];
	for (int j=1;j<=18;j++)
		for (int i=1;i<=n-(1<<j);i++)
			g[i][j]=gcd(g[i][j-1], g[i+(1<<(j-1))][j-1]);
}

int get_gcd(int l, int r){
	if (l==r) return g[l][0];
	int p=0;
	while (l+(1<<(p+1)) <= r) p++;
	return gcd(g[l][p], get_gcd(l+(1<<p), r));
}

void build_r(){
	memset(rr,-1,sizeof(rr));
	for (int i=1;i<=n;i++){
		int l=i,r=n;
		while (l<=r){
			int mid=((r-l)>>1)+l;
			int now=get_gcd(i,mid);
			if (now == mid-i+1) {rr[i]=mid; break;} else
			if (now > mid-i+1) l=mid+1;
			else r=mid-1;
		}
	}
}

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build_ST();
	build_r();
	int nxt_bad = 0, now_ans = 0;
	for (int i=1;i<=n;i++){
		if (i>nxt_bad) nxt_bad = rr[i];
		if (i==nxt_bad) now_ans++;
		printf("%d ",now_ans);
	}
	printf("\n");
	return 0;
}