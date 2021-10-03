#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

// #define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=405,INF=(int)1<<30;

int t,n,m;
char a[maxn][maxn];
int sum[maxn][maxn];
int ans;

inline int get_sum(int i,int j,int k,int t){
	i=max(i,1);j=max(j,1);
	if (i>k || j>t) return 0;
	return sum[k][t]-sum[i-1][t]-sum[k][j-1]+sum[i-1][j-1];
}

signed main(){
	t=read();
	while (t--){
		n=read();m=read();
		ans=INF;
		// for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
		char ch=getchar();
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++){
				while (ch!='0' && ch!='1') ch=getchar();
				a[i][j]=ch;
				if (i!=n || j!=m) ch=getchar();
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(a[i][j]=='1');

		for (int i=1;i<=n;i++)
			for (int k=i+4;k<=n;k++){
				int pre=INF;
				for (int j=m-3;j>=1;j--){
					int now=get_sum(i+1,1,k-1,(j+3)-1) // middle
					 + ((j+3)-1 - get_sum(i,1,i,(j+3)-1)) // uppper border
					 + ((j+3)-1 - get_sum(k,1,k,(j+3)-1)) // lower border
					 + (k-i-1 - get_sum(i+1,(j+3),k-1,(j+3))); // right border
					pre=min(now,pre);

					now=pre
					 + (k-i-1 - get_sum(i+1,j,k-1,j)) // left border
					 - get_sum(i+1,1,k-1,j) // middle extra
					 - (j - get_sum(i,1,i,j)) // upper extra
					 - (j - get_sum(k,1,k,j)); // lower extra
					ans=min(ans,now);
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}