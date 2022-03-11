#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n;

int reverse(int x){
	int f=1;
	if (x<0) f=-1,x=-x;
	int ret=0;
	while (x) ret=ret*10+x%10,x/=10;
	return f*ret;
}

bool in_int(int x){
	return (-(1ll<<31) <= x) && (x <= (1ll<<31) -1);
}

signed main(){
	n=read();
	n=reverse(n);
	if (!in_int(n)) printf("0\n");
	else printf("%lld\n",n);
	return 0;
}