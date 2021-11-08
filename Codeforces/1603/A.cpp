#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

#define int long long

const int maxn=1e5+5;
const int N=1e5;

int t,n;
int a[maxn];

int gcd(int x,int y){
	return (!y)?x:gcd(y,x%y);
}

int lcm(int x,int y){
	return x/gcd(x,y)*y;
}

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int now=1;
		bool flg=false;
		for (int i=1;i<=n && i<22;i++){
			now=lcm(now,i+1);
			if (a[i]%now==0) {printf("NO\n"); flg=true; break;}
		}
		if (!flg) printf("YES\n");
	}
	return 0;
}