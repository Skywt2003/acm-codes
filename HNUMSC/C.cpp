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

const int maxn=2e6+5;

int t,n,k;

signed main(){
	t=read();
	while (t--){
		n=read(),k=read();
		if (n==4 && k==n-1) printf("-1\n"); else
		if (k==n-1){
			printf("%d %d\n",1,n-3);
			printf("%d %d\n",n-2,n-1);
			printf("%d %d\n",0,2);
			for (int i=3;i<n/2;i++)
				printf("%d %d\n",i,n-1-i);
		} else if (k==0){
			for (int i=0;i<n/2;i++) printf("%d %d\n",i,n-1-i);
		} else {
			printf("%d %d\n",0,n-1-k);
			printf("%d %d\n",n-1,k);
			for (int i=1;i<n/2;i++)
				if (i!=k && i!=(n-1)-k) printf("%d %d\n",i,n-1-i);
		}
	}
	return 0;
}