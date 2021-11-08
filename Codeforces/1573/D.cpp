// UNAC

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5;
const int INF=(int)1<<60;

int t;
int n,cnt;
int a[maxn];

signed main(){
	t=read();
	while (t--){
		n=read(); cnt=0;
		for (int i=1;i<=n;i++) a[i]=read(),cnt+=a[i];
		if (cnt&1) printf("NO\n"); else
		if (n&1){
			printf("YES\n");
			for (int i=1;i<n;i+=2) printf("%lld ",i);
			for (int i=n-4;i>=1;i-=2) printf("%lld ",i);
			printf("\n");
		} else {
			int now=0;
			for (int i=1;i<=n;i++){
				now+=a[i];
				if ((i&1) && !(now&1)){
					for (int j=1;j<i;j+=2) printf("%lld ",j);
					for (int j=i-4;j>=1;j-=2) printf("%lld ",j);
					for (int j=i+1;j<n;j+=2) printf("%lld ",j);
					for (int j=n-4;j>=i+1;j-=2) printf("%lld ",j);
					printf("\n");
					break;
				}
			}
		}
	}
}