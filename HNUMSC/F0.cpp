#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<vector>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e6+5;

int n,k;
int f[maxn],ans[maxn];

signed main(){
	n=read(),k=read();
	while (k--){
		int x=read(),y=read();
		for (int i=x;i<=y;i++) ans[i]++;
	}

	std::sort(ans+1,ans+1+n);
	printf("%d",ans[(n+1)/2]);
	return 0;
}