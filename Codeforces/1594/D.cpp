#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5,maxe=1e6+5;

int t,n,m;
int p[maxn];
int tot,lnk[maxn],nxt[maxe],to[maxe],w[maxe];

void add_edge(int x,int y,int z){
	tot++; to[tot]=y; w[tot]=z;
	nxt[tot]=lnk[x]; lnk[x]=tot;
}

bool flg;
int nowcnt;

void DFS(int x){
	if (!flg) return;
	if (p[x]==1) nowcnt++;
	for (int i=lnk[x];i;i=nxt[i])
		if (p[to[i]]==-1) {p[to[i]]=(w[i])?(1-p[x]):p[x]; DFS(to[i]); }
		else if (p[to[i]] != ((w[i])?(1-p[x]):p[x])) {flg=false;return;}
}

void clearDFS(int x){
	p[x]=-1;
	for (int i=lnk[x];i;i=nxt[i]) if (p[to[i]]!=-1) clearDFS(to[i]);
}

signed main(){
	t=read();
	while (t--){
		n=read(); m=read();
		tot=0; for (int i=1;i<=n;i++) lnk[i]=0;
		while (m--){
			int x=read(),y=read();
			char ch=getchar(); while (ch!='i'&&ch!='c') ch=getchar();
			add_edge(x,y,(ch=='i')); add_edge(y,x,(ch=='i'));
		}
		for (int i=1;i<=n;i++) p[i]=-1;
		flg=true; int ans=0;
		for (int i=1;i<=n && flg;i++) if (p[i]==-1){
			nowcnt=0; p[i]=1; DFS(i); int xx=nowcnt;
			clearDFS(i);
			nowcnt=0; p[i]=0; DFS(i); int yy=nowcnt;
			ans+=max(xx,yy);
		}
		if (flg) printf("%lld\n",ans); else printf("-1\n");
	}
	return 0;
}