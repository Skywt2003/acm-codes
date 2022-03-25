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

const int maxn=1005;

int t;
int n;

std::pair<int,int> a[maxn];
int ans[maxn];
bool vis[maxn];

int getlen(std::pair<int,int> aa){
	return aa.second - aa.first + 1;
}

void splid(int now){
	if (a[now].first == a[now].second) {ans[now]=a[now].first; return;}
	int li=-1,lmax=0,ri=-1,rmax=0;
	for (int i=1;i<=n;i++) if (!vis[i]){
		if (a[i].first  == a[now].first  && getlen(a[i]) > lmax) lmax=getlen(a[i]),li=i;
		if (a[i].second == a[now].second && getlen(a[i]) > rmax) rmax=getlen(a[i]),ri=i;
	}
	if (li==-1) ans[now]=a[now].first,vis[ri]=true,splid(ri); else
	if (ri==-1) ans[now]=a[now].second,vis[li]=true,splid(li); else
	ans[now]=a[li].second+1,vis[li]=vis[ri]=true,splid(li),splid(ri);
}

signed main(){
	t=read();
	while (t--){
		memset(vis,0,sizeof(vis));
		n=read();
		int st=0;
		for (int i=1;i<=n;i++){
			a[i].first=read(),a[i].second=read();
			if (a[i].first == 1 && a[i].second == n) st=i;
		}
		vis[st]=true;
		splid(st);

		for (int i=1;i<=n;i++) printf("%d %d %d\n",a[i].first,a[i].second,ans[i]);
	}
	return 0;
}