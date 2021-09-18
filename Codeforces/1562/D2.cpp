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
map<int,vector<int> > lnk;

int find_b0(int x,int s){
	vector<int> vec=lnk[x];
	int l=1,r=vec.size(),ret=-1;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		if (vec[mid-1] >= s) ret=vec[mid-1],l=mid+1;
		else r=mid-1;
	}
	return ret;
}


signed main(){
	t=read();
	while (t--){
		memset(sum,0,sizeof(sum));
		lnk.clear();

		n=read(),q=read();
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) sum[i]=sum[i-1] + ((i&1)?1:-1)*((s[i]=='+')?1:-1);
		for (int i=1;i<=n;i++) lnk[sum[i]+sum[i-1]].push_back(i);

		while (q--){
			int l=read(),r=read();
			if (sum[r]-sum[l-1] == 0) printf("0\n"); else
			if ((r-l+1)&1){
				printf("1\n");
				printf("%lld\n",find_b0(sum[r]+sum[l-1],l));
			} else {
				printf("2\n");
				printf("%lld %lld\n",l,find_b0(sum[r]+sum[l],l+1));
			}
		}
	}
	return 0;
}