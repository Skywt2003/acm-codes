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

const int maxn=65;
const int tt=1e9+7;

int n;
int ans=1;

signed main(){
	n=read();
	if (n==1) {printf("6\n");return 0;}
	ans=4;
	for (int i=2;i<n;i++) ans=ans*ans%tt*4%tt;
	ans=ans*ans%tt*6%tt;
	printf("%lld\n",ans);
	return 0;
}