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

const int maxn=1e5+5,maxe=2e5+5;;

int t;
int n;
int f[maxn];
std::vector<std::pair<int,int> > edges;

int tot=0,lnk[maxn],nxt[maxe],to[maxe],id[maxe];
int ans[maxn];

void add_edge(int x,int y,int i){
	tot++,to[tot]=y;
	nxt[tot]=lnk[x];lnk[x]=tot;
	id[tot]=i;
}

void build_answer(int x,int fa,int num){
	for (int i=lnk[x];i;i=nxt[i]) if (to[i]!=fa){
		ans[id[i]]=num;
		build_answer(to[i],x,(num==2)?3:2);
	}
}

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			edges.push_back(std::make_pair(x,y));
			f[x]++,f[y]++;
			add_edge(x,y,i); add_edge(y,x,i);
		}
		if (n==2){
			printf("2\n");
		} else if (n==3){
			printf("2 3\n");
		} else {
			bool have_ans = true;
			for (int i=1;i<=n;i++) if (f[i]>=3) {have_ans=false;break;}
			if (!have_ans){
				printf("-1\n");
			} else {
				int s=-1;
				for (int i=1;i<=n;i++) if (f[i]==1) {s=i;break;}
				build_answer(s,-1,3);
				for (int i=1;i<n;i++) printf("%d ",ans[i]);
				printf("\n");
			}
		}
		memset(f,0,(n+1)*sizeof(int));
		tot=0;
		memset(lnk,0,(n+1)*sizeof(int));
		memset(nxt,0,(n*2)*sizeof(int));
		memset(to,0,(n*2)*sizeof(int));
		memset(id,0,(n*2)*sizeof(int));
		edges.clear();
	}
	return 0;
}