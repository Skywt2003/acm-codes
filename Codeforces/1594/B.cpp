#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int t,n,k;

const int tt=1e9+7;
const int N=100000;
int js[N+5],inv[N+5];

int qsm(int a,int b){
	int ret=1,w=a%tt;
	while (b){
		if (b&1) ret=ret*w%tt;
		w=w*w%tt; b>>=1;
	}
	return ret;
}

signed main(){
	t=read();
	while (t--){
		n=read();k=read();
		int nn=log2(k);
		k-=qsm(2LL,nn)-1;
		int ans=qsm(n,nn);
		int now=1; k--;
		while (k){
			if (k&1) ans=(ans+now)%tt;
			now=now*n%tt; k>>=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}