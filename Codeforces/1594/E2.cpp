// UNAC

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxk=65,maxn=2005;
const int tt=1e9+7;
const int no[7]={-1, 2, 1, 4, 3, 6, 5};

int k,n;

map<int,int> dp[7];
map<int,int> vis;

int get_color(char ch){
	if (ch=='w') return 1; else
	if (ch=='y') return 2; else
	if (ch=='g') return 3; else
	if (ch=='b') return 4; else
	if (ch=='r') return 5; else
	if (ch=='o') return 6; else
	printf("ERROR\n");
	return 0;
}

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

int get_dp(int x,int y){
	if (vis[x]) return dp[x][y];
	else return qsm(4LL,(1LL<<(k-(int)log2(x)))-2);
}

signed main(){
	k=read();
	n=read();
	for (int i=1;i<=n;i++){
		int x=read();
		char ch=getchar(); while (ch<'a'||ch>'z') ch=getchar();
		if (vis[x]){
			vis[x]=get_color(ch);
			for (int j=1;j<=6;j++) if (j!=get_color(ch)) dp[x][j]=0;
		} else {
			dp[x][get_color(ch)]=get_dp(x,get_color(ch));
			vis[x]=get_color(ch);
		}
		x>>=1;
		while (x){
			if (!vis[x]){
				vis[x]=-1;
				for (int j=1;j<=6;j++){
					dp[x][j]=0;
					for (int k=1;k<=6;k++) if (k!=j && k!=no[j])
						for (int t=1;t<=6;t++) if (t!=j && t!=no[j])
							dp[x][j]=(dp[x][j] + get_dp(x<<1,k) * get_dp((x<<1)+1,t) % tt)%tt;
				}
			} else {
				int j=vis[x];
				dp[x][j]=0;
				for (int k=1;k<=6;k++) if (k!=j && k!=no[j])
					for (int t=1;t<=6;t++) if (t!=j && t!=no[j])
						dp[x][j]=(dp[x][j] + get_dp(x<<1,k) * get_dp((x<<1)+1,t) % tt)%tt;
			}
			x>>=1;
		}
	}
	if ((!vis[1]) || (vis[1]==-1)){
		int ans=0;
		for (int i=1;i<=6;i++) ans = (ans+get_dp(1,i))%tt;
		printf("%lld\n",ans);
	} else printf("%lld\n",get_dp(1,vis[1]));

	for (int i=1;i<1LL<<k;i++){
		printf("node %lld : ",i);
		for (int j=1;j<=6;j++) printf("%lld ",get_dp(i,j));
		printf("\n");
	}
	return 0;
}