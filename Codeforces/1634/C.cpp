#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;

int t,n,m;

signed main(){
	t=read();
	while (t--){
		n=read(),m=read();
		if (m!=1 && n&1){
			printf("NO\n");
		} else {
			printf("YES\n");
			if (m==1) for (int i=1;i<=n;i++) printf("%lld\n",i);
			else {
				int x1=1,x2=2;
				for (int i=1;i<=n;i++){
					for (int j=0;j<m;j++) printf("%lld ",((i&1)?x1:x2)+j*2);
					if (i&1) x1+=m*2; else x2+=m*2;
					printf("\n");
				}
			}
		}
	}
	return 0;
}