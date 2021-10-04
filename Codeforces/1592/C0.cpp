// Fail
// 这个版本的主要问题是把所有切割的操作都理解为可以通过分离子树完成。
// 反例数据（来自 testcase#2 第4组）：
/*
9 4
377804615 522874068 101778092 409548873 334317788 230030759 377804615 295237531 404145046
1 9
4 5
7 3
4 8
3 4
4 6
2 3
9 3
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
// #define int long long
 
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
 
const int maxn=1e5+5,maxe=2e5+5;
const int INF=1<<30;
 
int t,n,k;
int a[maxn];
 
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int fa[maxn],xx[maxn];
bool vis[maxn];
 
void add_edge(int x,int y){
	tot++,to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}
 
void build_tree(int x){
	vis[x]=true; xx[x]=a[x];
	for (int i=lnk[x];i;i=nxt[i])
		if (!vis[to[i]]) fa[to[i]]=x,build_tree(to[i]),xx[x]^=xx[to[i]];
}
 
pair<int,int> find_xor(int x){
	vis[x]=true;
	pair<int,int> ret=make_pair(INF,INF);
	if (x!=1 && xx[x]==xx[1]) ret.first=1;
	int f1=INF,f2=INF;
	for (int i=lnk[x];i;i=nxt[i]) if (!vis[to[i]]){
		pair<int,int> now=find_xor(to[i]);
		if (now.second!=INF) ret.second=min(ret.second,now.second);
		if (now.first!=INF){
			ret.first=min(ret.first,now.first);
			if (now.first < f1) f1=now.first; else
			if (now.first < f2) f2=now.first;
		}
	};
	if (f1!=INF && f2!=INF) ret.second=min(ret.second,f1+f2);
	return ret;
}
 
signed main(){
	t=read();
	while (t--){
		n=read(); k=read();
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			add_edge(x,y);add_edge(y,x);
		}
 
		build_tree(1);
		if (xx[1]==0) printf("YES\n"); else {
			for (int i=1;i<=n;i++) vis[i]=false;
			pair<int,int> now=find_xor(1);
			if (now.second <= k-1) printf("YES\n"); else printf("NO\n");
		}
 
		tot=0;
		for (int i=1;i<=n;i++) lnk[i]=fa[i]=vis[i]=0;
	}
	return 0;
}