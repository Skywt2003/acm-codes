#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int t;
int n,m,x,y,a,b;

signed main(){
	t=read();
	while (t--){
		n=read(),m=read();
		x=read(),y=read();
		a=read(),b=read();
		if (a==x || b==y) {printf("0\n"); continue;}
		int dx=1,dy=1;
		int ans=0;
		for (;;){
			if (x+dx > n || x+dx < 1) dx=-dx;
			if (y+dy > m || y+dy < 1) dy=-dy;
			x+=dx; y+=dy; ans++;
			if (x==a || y==b) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}