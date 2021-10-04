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
int fa[maxn],depth[maxn],xx[maxn];
bool vis[maxn];
bool flg;

void add_edge(int x,int y){
	tot++,to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
}

void build_tree(int x){
	xx[x]=a[x];
	for (int i=lnk[x];i;i=nxt[i]) if (!depth[to[i]])
		fa[to[i]]=x,depth[to[i]]=depth[x]+1,build_tree(to[i]),xx[x]^=xx[to[i]];
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

		depth[1]=1; build_tree(1);
		if (xx[1]==0) printf("YES\n"); else {
			if (2 > k-1) printf("NO\n"); else {
				int dep1=0,num1=-1;
				for (int i=2;i<=n;i++) if (xx[i]==xx[1] && depth[i]>dep1) dep1=depth[i],num1=i;
				if (num1==-1) printf("NO\n"); else{
					int now=fa[num1];
					while (now!=1) xx[now]^=xx[1],now=fa[now];
					vis[num1]=true;
					flg=false;
					for (int i=2;i<=n;i++) if ((!vis[i]) && xx[i]==xx[1]){flg=true;break;}
					if (flg) printf("YES\n"); else printf("NO\n");
					vis[num1]=false;
				}
			}
		}
		tot=0;
		for (int i=1;i<=n;i++) lnk[i]=fa[i]=depth[i]=0;
	}
	return 0;
}