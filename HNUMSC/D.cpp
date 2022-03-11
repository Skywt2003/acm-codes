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

const int maxn=25;

int n;
int a[maxn][maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=read();
	
	for (int i=1;i<=n;i++){
		for (int j=n;j>=1;j--) printf("%d ",a[j][i]);
		printf("\n");
	}
	return 0;
}