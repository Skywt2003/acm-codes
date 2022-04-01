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
int sum[maxn][maxn];

int vis[maxn][maxn];

int get_count(int x1,int y1,int x2,int y2){
	// if (x1<1) x1=1; if (x2<1) return 0;
	// if (y1<1) y1=1; if (y2<1) return 0;
	// if (x2>n) x2=n; if (x1>n) return 0;
	// if (y2>m) y2=m; if (y1>m) return 0;
	// printf("GET COUNT: %d %d %d %d = %d\n",x1,y1,x2,y2,sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
	return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}

int get_all(int x1,int y1,int x2,int y2){
	return (x2-x1+1)*(y2-y1+1);
}

void set_flg(int x1,int x2,int y,int t){
	for (int i=x1;i<=x2;i++) vis[i][y]=t;
}

signed main(){
	t=read();
	while (t--){
		n=read(),m=read();
		char ch=getchar(); while (ch!='1'&&ch!='0') ch=getchar();
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				a[i][j] = (ch=='1');
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
				if (i==n && j==m) continue;
				ch=getchar(); while (ch!='1'&&ch!='0') ch=getchar();
			}
		}
		bool ans=true;
		for (int i=1;i<=n && ans;i++){
			int flg=0;
			for (int j=1;j<=m && ans;j++){
				flg+=vis[i][j];
				if (flg) continue;
				if (a[i][j]){
					int k=i,t=j;
					while (k+1<=n && a[k+1][j]) k++;
					while (t+1<=m && a[i][t+1]) t++;
					// printf("checking %d %d %d %d\n",i,j,k,t);
					if (get_count(i,j,k,t) != get_all(i,j,k,t)) ans=false;
					// if (!ans) printf("First failed\n");
					if (i-1>=1 && get_count(i-1,j,i-1,t)) ans=false;
					if (k+1<=n && get_count(k+1,j,k+1,t)) ans=false;
					if (j-1>=1 && get_count(i,j-1,k,j-1)) ans=false;
					if (t+1<=m && get_count(i,t+1,k,t+1)) ans=false;
					// if (!ans) printf("Failed: %d %d %d %d",i,j,k,t);
					set_flg(i,k,j,-1);
					set_flg(i,k,t+1,1);
					flg+=vis[i][j];
				}
			}
		}
		printf(ans?"yes\n":"no\n");
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
