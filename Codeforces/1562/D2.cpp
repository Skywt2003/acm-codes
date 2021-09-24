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

const int maxn=3e5+5;

int t;
int n,q;

char s[maxn];
int sum[maxn];

int get_b(int x,int l,int r){
	return (sum[x-1]-sum[l-1])-(sum[r]-sum[x]);
}

int find_b0(int l,int r){ // 默认排除边界
	int ll=l,rr=r,bl=get_b(l,l,r),br=get_b(r,l,r);
	if (bl==0) return l; if (br==0) return r;
	while (ll+1 < rr){
		int mid=((rr-ll)>>1)+ll,bmid=get_b(mid,l,r);
		if (bmid == 0) return mid; else
		if (bmid*bl < 0) rr=mid,br=bmid;
		else ll=mid,bl=bmid;
	}
	printf("ERROR: Not found.\n");
	return 0;
}

signed main(){
	t=read();
	while (t--){
		memset(sum,0,sizeof(sum));

		n=read(),q=read();
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]+((i&1)?1:-1)*((s[i]=='+')?1:-1);

		while (q--){
			int l=read(),r=read();
			if (sum[r]-sum[l-1]==0) printf("0\n"); else
			if ((r-l+1)&1) printf("1\n%lld\n",find_b0(l,r)); else
			printf("2\n%lld %lld\n",l,find_b0(l+1,r));
		}
	}
	return 0;
}