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

const int maxn=105;

int t,n,d;

bool is_prime(int x){
	if (x==1) return true;
	if (x==2) return true;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i == 0) return false;
	return true;
}

signed main(){
	t=read();
	while (t--){
		n=read(), d=read();
		if (n%(d*d) != 0) printf("NO\n");
		else {
			// int dd = d, k = n;
			// while (k%dd == 0) k/=dd, dd*=d;
			int k=n;
			while (k%d == 0) k/=d;
			if (is_prime(k) && is_prime(d)) printf("NO\n"); else
			printf("YES\n");
		}
	}
	return 0;
}
