#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=1e5+5;
const int N=1e5;

int t,n;
int a[maxn];

bool vis[maxn];
int cnt[maxn],mul[maxn];
int prime[maxn],id[maxn];

void build_prime(){
	vis[1]=false; vis[2]=true; prime[++prime[0]]=2,id[2]=1;
	for (int i=3;i<=N;i++){
		vis[i]=true;
		for (int j=2;j<=sqrt(i);j++) if (i%j==0) {vis[i]=false;break;}
		if (vis[i]) prime[++prime[0]]=i,id[i]=prime[0];
	}
}

signed main(){
	build_prime();
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) cnt[i]=0,mul[i]=1;
		int num=1;
		bool flg=true;
		for (int i=1;i<=n;i++){
			a[i]=read();
			int now=i+1;
			for (int j=1;prime[j]<i+1 && j<=prime[0] && now>1;j++) if (now%prime[j]==0){
				if (now%mul[j]) {while (now%prime[j]==0) now/=prime[j];}
				else now/=mul[j];
			}
			mul[id[now]]*=now; cnt[id[now]]++;
			if (num*now <= 1e9) num*=now;
			if (a[i]%num == 0) flg=false;
		}
		printf((flg)?"YES\n":"NO\n");
	}
	return 0;
}