#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3e4+5;

int n,k;
int a[maxn];
int orr[maxn],andr[maxn];

signed main(){
	n=read();k=read();
	for (int i=2;i<=n;i++){
		printf("and %lld %lld\n",(int)1,i);
		fflush(stdout);
		andr[i]=a[i]=read(); a[1]|=andr[i];
	}
	for (int i=2;i<=n;i++){
		printf("or %lld %lld\n",(int)1,i);
		fflush(stdout);
		orr[i]=read();
		for (int j=0;j<32;j++){
			int now=(int)1<<j;
			if ((andr[i]&now)==0 && (orr[i]&now)){
				// printf("Sat!\n");
				if ((a[1]&now)==0) a[i]|=now;
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%lld ",a[i]);printf("\n");
	sort(a+1,a+1+n);
	printf("finish %lld\n",a[k]);

	return 0;
}