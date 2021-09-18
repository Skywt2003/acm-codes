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

int t,c,d;

signed main(){
	t=read();
	while (t--){
		c=read();d=read();
		if (abs(c-d)&1) printf("-1\n"); else{
			if (c==0 && d==0) printf("0\n"); else
			if (c==d) printf("1\n"); else
			printf("2\n");
		}
	}
	return 0;
}