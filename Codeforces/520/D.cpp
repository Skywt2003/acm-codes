#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<set>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5,tt=1e9+9;

struct cube{
	int x,y,id;
	bool operator <(const cube& bb)const{return id<bb.id;}
	bool operator >(const cube& bb)const{return id>bb.id;}
};

int m;
cube c[maxn];
int cnt[maxn],ans=0;

map<pair<int,int>,int> lnk;
multiset<cube> que;

bool only_rely(int x,int y){
	int cnt=0;
	if (lnk[make_pair(x,y-1)]) cnt++;
	if (lnk[make_pair(x-1,y-1)]) cnt++;
	if (lnk[make_pair(x+1,y-1)]) cnt++;
	return cnt==1;
}

bool can_delete(int x,int y){
	if (y<0 || lnk[make_pair(x,y)]==0) return false;
	if (lnk[make_pair(x,y+1)] && only_rely(x,y+1)) return false;
	if (lnk[make_pair(x-1,y+1)] && only_rely(x-1,y+1)) return false;
	if (lnk[make_pair(x+1,y+1)] && only_rely(x+1,y+1)) return false;
	return true;
}

signed main(){
	m=read();
	for (int i=1;i<=m;i++){
		c[i].x=read();c[i].y=read();c[i].id=i;
		lnk[make_pair(c[i].x,c[i].y)]=i;
	}
	for (int i=1;i<=m;i++) if (can_delete(c[i].x,c[i].y)) que.insert(c[i]);

	int round=1;
	while (!que.empty()){
		cube now;
		if (round&1) now=*--que.end(),que.erase(--que.end());
		else now=*que.begin(),que.erase(que.begin());
		int xx=now.x,yy=now.y;
		if (!can_delete(xx,yy)) continue;
		ans=(ans*m%tt+(now.id-1))%tt;
		lnk[make_pair(xx,yy)]=0;
		if (can_delete(xx,yy-1)) que.insert(c[lnk[make_pair(xx,yy-1)]]);
		if (can_delete(xx-1,yy-1)) que.insert(c[lnk[make_pair(xx-1,yy-1)]]);
		if (can_delete(xx+1,yy-1)) que.insert(c[lnk[make_pair(xx+1,yy-1)]]);
		round++;
	}

	printf("%lld\n",ans);
	return 0;
}