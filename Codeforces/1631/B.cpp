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

const int maxn=2e5+5;

int n,t;
int a[maxn];
int ans;

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int now_size = 1;
		for (;;){
			bool flg=false;
			for (int i=std::max(1,n-now_size*2+1); i<=n-now_size; i++)
				if (a[i]!=a[n]) {flg=true;break;}
			ans+=flg;
			now_size *= 2;
			if (now_size >= n) break;
		}
		printf("!!!%d\n",ans);
	}
	return 0;
}