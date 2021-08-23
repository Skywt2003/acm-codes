#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define int long long

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005,maxk=1000005;
const int INF=(long long)1<<60;

int n,m,k,p;
int a[maxn][maxn];
int col[maxk],row[maxk];
int ans=-INF;

priority_queue<int, vector<int>, less<int> > que;

signed main(){
	n=read();m=read();k=read();p=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=read();
	
	while (!que.empty()) que.pop();
	for (int i=1;i<=n;i++){
		int sum=0;
		for (int j=1;j<=m;j++) sum+=a[i][j];
		que.push(sum);
	}
	for (int i=1;i<=k;i++){
		int now=que.top(); que.pop();
		row[i]=row[i-1]+now;
		que.push(now-m*p);
	}

	while (!que.empty()) que.pop();
	for (int j=1;j<=m;j++){
		int sum=0;
		for (int i=1;i<=n;i++) sum+=a[i][j];
		que.push(sum);
	}
	for (int i=1;i<=k;i++){
		int now=que.top(); que.pop();
		col[i]=col[i-1]+now;
		que.push(now-n*p);
	}

	for (int i=0;i<=k;i++) ans=max(ans,row[i]+col[k-i]-i*(k-i)*p);
	printf("%lld\n",ans);
	return 0;
}