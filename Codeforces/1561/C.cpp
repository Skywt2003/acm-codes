#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;

int t;
int n;
pair<int,int> k[maxn];
int ans,now;

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++){
			k[i].second=read();
			k[i].first=1;
			for (int j=1;j<=k[i].second;j++){
				int x=read();
				k[i].first=max(k[i].first,x-j+2);
			}
		}
		sort(k+1,k+1+n);
		ans=1; now=1;
		for (int i=1;i<=n;i++){
			if (now<k[i].first) ans+=k[i].first-now,now=k[i].first;
			now+=k[i].second;
		}
		printf("%lld\n",ans);
	}
	return 0;
}