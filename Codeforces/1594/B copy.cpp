// UNAC

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

// int find_nn(int k){
// 	int l=1,r=100000,ret=0;
// 	while (l<=r){
// 		int mid=((r-l)>>1)+l;
// 		if ((mid+1)*mid < k*2) ret=mid,l=mid+1;
// 		else r=mid-1;
// 	}
// 	return ret;
// }

// void build_js(){
// 	js[0]=js[1]=1;
// 	for (int i=2;i<=N;i++) js[i]=js[i-1]*i%tt,inv[i]=qsm(js[i],tt-2);
// }

// int C(int n,int m){
// 	return js[n]*inv[n-m]%tt*inv[m]%tt;
// }

// int find_nnn(int nn,int k){
// 	int l=0,r=k,ret=0;
// 	while (l<=r){
// 		int mid=((r-l)>>1)+l;
// 		if (C(nn+1,mid+1)-1 <= k) ret=mid,l=mid+1;
// 		else r=mid-1;
// 	}
// 	return ret;
// }

signed main(){
	// build_js();
	t=read();
	while (t--){
		n=read();k=read();
		// int nn=find_nn(k);
		// printf("k=%lld nn=%lld\n",k,nn);
		// k-=nn*(nn+1)/2;
		

		int ans=qsm(n,nn);
		// int nnn=find_nnn(nn,k);
		// printf("ks=%lld nnn=%lld\n",k,nnn);
		// k-=C(k+1,nnn+1)-1;
		int now=1; k--;
		while (k){
			if (k&1) ans=(ans+now)%tt;
			now=now*n%tt; k>>=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}