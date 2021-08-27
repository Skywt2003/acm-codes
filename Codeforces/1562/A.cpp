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

int t,l,r;

signed main(){
	t=read();
	while (t--){
		l=read();r=read();
		if ((r/2+1) >= l) printf("%lld\n",r%(r/2+1));
		else printf("%lld\n",r%l);
	}
	return 0;
}