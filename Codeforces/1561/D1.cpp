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

const int maxn=4e6+5;

int n,m;
int f[maxn];
int sum=0;

signed main(){
	n=read();m=read();

	f[1]=1; sum=1;
	for (int i=2;i<=n;i++){
		f[i]=sum;
		int x=i,j=1,nxtx,nxtj;
		while (j<i){
			nxtj=j+1; nxtx=i/nxtj; nxtj=i/nxtx;
			f[i]=(f[i]+f[j]*(x-nxtx)%m)%m;
			x=nxtx; j=nxtj;
		}
		sum+=f[i];
	}
	printf("%lld\n",f[n]);
	return 0;
}