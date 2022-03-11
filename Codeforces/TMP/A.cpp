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

int t;
int n,k;
std::pair<int,int> a[maxn];

signed main(){
	t=read();
	while (t--){
		n=read(); k=read();
		for (int i=1;i<=n;i++) a[i].first=read();
		for (int i=1;i<=n;i++) a[i].second=read();
		std::sort(a+1,a+1+n);
		for (int i=1;i<=n;i++) if (a[i].first <= k) k+=a[i].second; else break;
		printf("%d\n",k);
	}
	return 0;
}