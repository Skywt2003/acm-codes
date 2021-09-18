#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5;
const int INF=(int)1<<60;

int t,n;
int a[maxn],aa[maxn],bb[maxn];

signed main(){
	t=read();
	while (t--){
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));

		n=read();
		for (int i=1;i<=n;i++){
			a[i]=read()&1;
			if (a[i]) aa[++aa[0]]=i; else bb[++bb[0]]=i;
		}

		if (abs(aa[0]-bb[0])>1) {printf("-1\n");continue;}

		int ans1=INF,ans2=INF;
		if ((!(n&1)) || ((n&1)&&(bb[0]>aa[0]))){
			ans1=0;
			for (int i=1;i<=bb[0];i++) ans1+=abs(bb[i]-(2*i-1));
		}
		if ((!(n&1)) || ((n&1)&&(aa[0]>bb[0]))){
			ans2=0;
			for (int i=1;i<=bb[0];i++) ans2+=abs(bb[i]-2*i);
		}

		printf("%lld\n",min(ans1,ans2));
	}
	return 0;
}