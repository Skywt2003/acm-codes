#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=3e5+5;

int t,n;
char ch;
char s[maxn];
int a[maxn];

signed main(){
	t=read();
	while (t--){
		n=read(); ch=getchar();while (ch<'a'||ch>'z') ch=getchar();
		scanf("%s",s+1);
		int cnt=0;
		for (int i=1;i<=n;i++){
			a[i]=(s[i]==ch)?1:0;
			cnt+=a[i];
		}
		
		if (cnt==n) printf("0\n"); else {
			int lst=-1;
			for (int i=n;i>=1;i--) if (a[i]) {lst=i;break;}
			bool flg=true;
			for (int j=lst;j<=n;j+=lst) if (!a[j]) {flg=false;break;}
			if (flg) printf("1\n%lld\n",lst);
			else printf("2\n%lld %lld\n",n-1,n);
		}
	}
	return 0;
}