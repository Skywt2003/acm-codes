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

const int maxn=1e5+5;

int t,n,x;
int a[maxn],b[maxn];

signed main(){
	t=read();
	while (t--){
		n=read(); x=read();
		for (int i=1;i<=n;i++) a[i]=b[i]=read();
		sort(b+1,b+1+n);
	
		bool flg=true;
		for (int i=1;i<n;i++) if (a[i]>a[i+1]) flg=false;
		if (flg) {printf("YES\n");continue;}

		if (x <= n/2) printf("YES\n"); else {
			flg=true;
			for (int i=n-x+1;i<=x;i++) if (a[i]!=b[i]) flg=false;
			printf(flg?"YES\n":"NO\n");
		}
	}
	return 0;
}