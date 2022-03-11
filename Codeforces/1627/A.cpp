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

const int maxn=55;

int t;
int n,m,x,y;
char s[maxn][maxn];

bool row_have_black(int x){
	for (int i=1;i<=m;i++) if (s[x][i] == 'B') return true;
	return false;
}

bool col_have_black(int x){
	for (int i=1;i<=n;i++) if (s[i][x] == 'B') return true;
	return false;
}

bool have_black(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j] == 'B') return true;
	return false;
}

signed main(){
	t=read();
	while (t--){
		n=read(),m=read(),x=read(),y=read();
		for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
		
		// printf("[");
		if (s[x][y] == 'B') printf("0\n"); else
		if (row_have_black(x) || col_have_black(y)) printf("1\n"); else
		if (have_black()) printf("2\n");
		else printf("-1\n");
		// printf("]");
	}
	return 0;
}