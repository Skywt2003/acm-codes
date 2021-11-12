#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

// #define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e7+5,maxm=1e6+5;

int n,m;
char s[maxn];

vector<int> vec[maxn];
priority_queue<int> now;
int cnt[150];
bool inheap[150];

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
		for (int j=0;j<vec[i].size();j++){
			if (vec[i][j]>0) cnt[vec[i][j]]++; else vec[i][j]=-vec[i][j],cnt[vec[i][j]]--;
			if (cnt[vec[i][j]] && !inheap[vec[i][j]]) inheap[vec[i][j]]=true,now.push(vec[i][j]);
		}
		while (!now.empty() && cnt[now.top()]==0) inheap[now.top()]=false,now.pop();
		ans+=(now.empty()?s[i-1]:max((int)s[i-1],now.top()));
	}
	printf("%d\n",ans);
	return 0;
}