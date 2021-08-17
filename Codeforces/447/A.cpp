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

const int maxn=305;

int p,n,a[maxn];

signed main(){
	p=read();n=read();
	for (int i=0;i<p;i++) a[i]=-1;
	for (int i=0;i<n;i++){
		int x=read();
		if (a[x%p]!=-1){
			printf("%lld\n",i+1);
			return 0;
		} else a[x%p]=x;
	}
	printf("-1\n");
	return 0;
}