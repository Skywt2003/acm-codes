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

const int maxn=10005,N=10000;
int n,m;

int step[maxn];

queue<pair<int,int> > que;

signed main(){
	for (int i=1;i<=N;i++) step[i]=-1;
	n=read();m=read();
	
	que.push(make_pair(n,0)); step[n]=0;
	while (!que.empty()){
		pair<int,int> now=que.front(); que.pop();
		if (now.first*2<=N && step[now.first*2]==-1) que.push(make_pair(now.first*2,now.second+1)),step[now.first*2]=now.second+1;
		if (now.first-1>0 && step[now.first-1]==-1) que.push(make_pair(now.first-1,now.second+1)),step[now.first-1]=now.second+1;
	}

	printf("%lld\n",step[m]);
	return 0;
}