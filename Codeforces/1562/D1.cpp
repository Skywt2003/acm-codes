#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3e5+5;

int t;
int n,q;

char s[maxn];
int sum[maxn];

signed main(){
	t=read();
	while (t--){
		n=read(),q=read();
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) sum[i]=sum[i-1] + ((i&1)?1:-1)*((s[i]=='+')?1:-1);
		while (q--){
			int l=read(),r=read();
			if (sum[r]-sum[l-1]==0) printf("0\n"); else
			if ((r-l+1)&1) printf("1\n"); else
			printf("2\n");
		}
	}
	return 0;
}