#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5,maxe=2e5+5;
const int INF=(int)1<<60;

int t;
int n;
int ind[maxn];
int tot,lnk[maxn],nxt[maxe],to[maxe];
int depth[maxn];
bool vis[maxn];
bool flg;

queue<int> que;

void clear_edges(){
	tot=0;
	// memset(lnk,0,sizeof(lnk));
	// memset(ind,0,sizeof(ind));
	// memset(vis,0,sizeof(vis));
	// memset(depth,0,sizeof(depth));
	while (!que.empty()) que.pop();
}

void add_edge(int x,int y){
	tot++;
	to[tot]=y; ind[y]++;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

signed main(){
	t=read();
	while (t--){
		clear_edges();
		n=read();
		for (int i=1;i<=n;i++){
			int x=read();
			while (x--){
				int now=read();
				add_edge(now,i);
			}
		}
		int ans=1; flg=true;
		for (int i=1;i<=n;i++) if (ind[i]==0) vis[i]=true,que.push(i),depth[i]=1;
		if (que.empty()) flg=false;
		while (!que.empty()){
			int now=que.front(); que.pop();
			for (int i=lnk[now];i;i=nxt[i]){
				if (vis[to[i]]) {flg=false;break;}
				ind[to[i]]--;
				depth[to[i]]=max(depth[to[i]],depth[now]+(to[i]<now));
				ans=max(ans,depth[to[i]]);
				if (ind[to[i]]==0) vis[to[i]]=true,que.push(to[i]);
			}
			if (!flg) break;
		}
		if (flg) printf("%lld\n",ans); else printf("-1\n");
		for (int i=1;i<=n;i++) lnk[i]=ind[i]=depth[i]=0,vis[i]=false;
	}
	return 0;
}