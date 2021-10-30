#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=2e5+5;

int t,n;
int a[maxn];

signed main(){
	t=read();
	while (t--){
		n=read();
		bool flg=false;
		for (int i=1;i<=n;i++){
			a[i]=read();
			if (i>1 && a[i]<=a[i-1]) flg=true;
		}
		if (!(n&1) || flg) printf("YES\n"); else printf("NO\n");
	}
	return 0;
}