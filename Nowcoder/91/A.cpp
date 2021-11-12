#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int t,n,m;

signed main(){
	t=read();
	while (t--){
		n=read(),m=read();
		int ans=0;
		while (n!=1){
			ans++;
			if (n<=m) break;
			int x=n/(m+1),y=n%(m+1);
			n=x+(bool)y;
		}
		printf("%lld\n",ans);
	}
	return 0;
}