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

const int maxn=2e5+5,tt=1e9+7,N=2e5;;

int t,n;
int js[maxn];

signed main(){
	js[0]=1; js[1]=1;
	js[2]=1;
	for (int i=3;i<=N;i++) js[i]=js[i-1]*i%tt;

	t=read();
	while (t--){
		n=read();
		printf("%lld\n",js[n*2]);
	}
	return 0;
}