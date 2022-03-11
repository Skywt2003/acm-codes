#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;

int t,n;

bool is_2n(int x){
	return log2(x) == (int)(log2(x));
}

signed main(){
	t=read();
	while (t--){
		n=read();
		int ans=-1;
		for (int i=n-1;i>=0;i--) if (is_2n(i)) {ans=i;break;}
		for (int i=1;i<ans;i++) printf("%d ",i);
		printf("0 ");
		for (int i=ans;i<n;i++) printf("%d ",i);
		printf("\n");
	}
	return 0;
}