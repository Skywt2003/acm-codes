#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2e5+5,maxe=4e5+5;

int n,m;
int x,y,z;
int tot=0,lnk[maxn],nxt[maxe],to[maxe];
int stat[maxn];

int dist[maxn];
bool vis[maxn];

void add_edge(int x,int y){
    tot++;to[tot]=y;
    nxt[tot]=lnk[x];lnk[x]=tot;
}

priority_queue<pair<int,int> > heap;

void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	while (!heap.empty()) heap.pop();
	dist[s]=0; heap.push(make_pair(0,s));
	while (!heap.empty()){
		int head=heap.top().second; heap.pop();
		if (head==n) break;
        if (vis[head]) continue;
		vis[head]=true;
		for (int i=lnk[head];i;i=nxt[i]){
            int w = (stat[head]==stat[to[i]])?min(x,y+z):min(y,x+z);
			if (vis[to[i]]==false && dist[head]+w < dist[to[i]]){
				dist[to[i]]=dist[head]+w;
				heap.push(make_pair(-dist[to[i]],to[i]));
			}
        }
	}
}

signed main(){
    n=read(),m=read();
    x=read(),y=read(),z=read();
    for (int i=1;i<=n;i++) stat[i]=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read();
        add_edge(x,y);add_edge(y,x);
    }
    dijkstra(1);
    printf("%lld\n",dist[n]);
    return 0;
}