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

const int maxn=150005,maxx=3e5+5;

int t;
int n;
int a[maxn];
int lst[maxx];

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int ans=-1;
		for (int i=1;i<=n;i++){
			if (lst[a[i]]) ans=std::max(ans, (n-i) + (lst[a[i]]-1) + 1);
			lst[a[i]]=i;
		}
		printf("%d\n",ans);
		for (int i=1;i<=n;i++) lst[a[i]]=0;
	}
	return 0;
}