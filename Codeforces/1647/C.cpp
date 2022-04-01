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

int t,n,m;

bool a[maxn][maxn];

signed main(){
	t=read();
	while (t--){
		int cnt=0;
		n=read(),m=read();
		char ch=getchar(); while (ch!='1'&&ch!='0') ch=getchar();
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				a[i][j] = (ch=='1'); cnt+=a[i][j];
				if (i==n && j==m) continue;
				ch=getchar(); while (ch!='1'&&ch!='0') ch=getchar();
			}
		}
		if (a[1][1]){printf("-1\n"); continue;}
		printf("%d\n",cnt);
		for (int i=n;i>=1;i--)
			for (int j=m;j>=2;j--) 
				if (a[i][j]) printf("%d %d %d %d\n",i,j-1,i,j);
		for (int i=n;i>=2;i--)
			if (a[i][1]) printf("%d %d %d %d\n",i-1,1,i,1);
	}
	return 0;
}
