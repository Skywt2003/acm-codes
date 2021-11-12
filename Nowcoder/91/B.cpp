#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5,maxm=1e5+5;

int n,m;
char s[maxn];

vector<int> vec[maxn];
priority_queue<int> now,del;

signed main(){
	n=read(),m=read();
	scanf("%s",s);
	for (int i=1;i<=m;i++){
		int x=read(),y=read();
		char ch=getchar(); while (ch==' ') ch=getchar();
		vec[x].push_back(ch); vec[y+1].push_back(-ch);
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<vec[i].size();j++)
			if (vec[i][j]>0) now.push(vec[i][j]); else 
			if (vec[i][j]<0) del.push(-vec[i][j]);
		while (!now.empty() && !del.empty() && now.top() == del.top()) now.pop(),del.pop();
		ans+=(now.empty()?s[i-1]:max((int)s[i-1],now.top()));
	}
	printf("%lld\n",ans);
	return 0;
}