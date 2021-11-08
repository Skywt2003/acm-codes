#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int t,x,y;

signed main(){
	t=read();
	while (t--){
		x=read(),y=read();
		if (x>y) printf("%lld\n",x+y);
		else printf("%lld\n",y-y%x/2);
	}
	return 0;
}