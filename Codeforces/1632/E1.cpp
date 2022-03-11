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

const int maxn=3e5+5;

int t,n;

int tot=0,lnk[maxn],nxt[maxn*2],to[maxn*2];

int fa[maxn],depth[maxn],depth_max[maxn],depth_a[maxn],depth_b[maxn];

int f[maxn];

void add_edge(int x,int y){
	tot++, to[tot]=y;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

void build_tree(int x){
	depth_max[x] = depth[x];
	for (int i=lnk[x]; i; i=nxt[i]) if (to[i] != fa[x]){
		fa[to[i]]=x; depth[to[i]]=depth[x]+1;
		build_tree(to[i]);
		depth_max[x] = std::max(depth_max[x], depth_max[to[i]]);
		if (depth_max[to[i]] > depth_a[x]){
			depth_b[x] = depth_a[x];
			depth_a[x] = depth_max[to[i]]; 
		} else if (depth_max[to[i]] > depth_b[x])
			depth_b[x] = depth_max[to[i]];
	}
	if (depth_a[x] && !depth_b[x]) depth_b[x] = depth[x];
}

void build_dp(){
	for (int i=1; i<=n; i++) if (depth_b[i])
		f[depth_b[i]-1] = std::max(f[depth_b[i]-1], depth_a[i]+depth_b[i]-2*depth[i]);
	for (int i=depth_max[1]-2;i>=0;i--) f[i] = std::max(f[i], f[i+1]);
}

int upfloor_div(int x,int y){
	return x/y + (x%y)?1:0;
}

int get_answer(int x){
	int ans=depth_max[1];
	int l=1,r=depth_max[1];
	while (l<=r){
		int mid=((r-l)>>1)+l;
		if (mid >= upfloor_div(f[mid],2) + x) ans=mid, r=mid-1;
		else l=mid+1;
	}
	return ans;
}

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			add_edge(x,y),add_edge(y,x);
		}

		build_tree(1);
		build_dp();

		for (int i=1;i<=n;i++) printf("%d ",get_answer(i));
		printf("\n");

		n++; tot++;
		memset(lnk,0,n*sizeof(int));
		memset(nxt,0,tot*sizeof(int));
		memset(to,0,tot*sizeof(int));
		tot=0;
		memset(fa,0,n*sizeof(int));
		memset(depth,0,n*sizeof(int));
		memset(depth_max,0,n*sizeof(int));
		memset(depth_a,0,n*sizeof(int));
		memset(depth_b,0,n*sizeof(int));
		memset(f,0,n*sizeof(int));
	}
	return 0;
}