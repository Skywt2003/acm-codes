#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int t,n,m,k;

signed main(){
	t=read();
	while (t--){
		n=read();m=read();k=read()-1;
		// if (m > n*(n-1)/2) printf("NO\n"); else
		// if (m == n*(n-1)/2) printf((1<=k)?"YES\n":"NO\n"); else
		// if (m >= 2*n-3) printf((2<=k)?"YES\n":"NO\n"); else
		// if (m >= n) printf((n/2<=k)?"YES\n":"NO\n"); else
		// if (m == n-1) printf((n-1<=k)?"YES\n":"NO\n"); else
		// if (m < n-1) printf("NO\n");

		if (k<=0) printf("NO\n"); else
		if (m<n-1 || m>n*(n-1)/2) printf("NO\n"); else
		if (k==1) printf((n==1)?"YES\n":"NO\n"); else
		if (k==2) printf((m==n*(n-1)/2)?"YES\n":"NO\n"); else
		printf("YES\n");
	}
	return 0;
}