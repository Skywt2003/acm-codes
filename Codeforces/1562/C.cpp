#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e4+5;

int t,n;
char s[maxn];

signed main(){
	t=read();
	while (t--){
		n=read();
		scanf("%s",s+1);
		
		int flg=false;
		for (int i=1;i<=n;i++) if (s[i]=='0'){
			if (i <= n/2) printf("%lld %lld %lld %lld\n",i,n,i+1,n);
			else printf("%lld %lld %lld %lld\n",(int)1,i,(int)1,i-1);
			flg=true;
			break;
		}
		if (flg) continue;
		printf("%lld %lld %lld %lld\n",(int)1,n-(n&1),(int)1,n/2);
	}

	return 0;
}