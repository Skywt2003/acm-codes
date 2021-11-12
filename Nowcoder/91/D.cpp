#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=5e5+5;
const int tt=1000000007;

int n,tot=0;
int a[5][maxn],sum[5][maxn];

vector<int> vec;
map<int,int> id;

class bitTree{
	private:
		int tree[maxn*2];
		int lowbit(int x){
			return x&(-x);
		}
	
	public:
		void clear(){
			memset(tree,0,sizeof(tree));
		}

		void change(int x,int delta){
			while (x<=tot) tree[x]+=delta,x+=lowbit(x);
		}

		int query(int x){
			int ret=0;
			while (x>=1) ret=(ret+tree[x])%tt,x-=lowbit(x);
			return ret;
		}
};

bitTree t;
int ans=0;

int find_id(int x){
	int l=0,r=tot-1;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		if (vec[mid]==x) return mid+1;
		if (x < vec[mid]) r=mid-1; else l=mid+1;
	}
	printf("err: not found\n");
	return 0;
}

signed main(){
	n=read();
	for (int k=1;k<=3;k++)
		for (int i=1;i<=n;i++)
			a[k][i]=read(),sum[k][i]=sum[k][i-1]+a[k][i];
	for (int i=1;i<=n;i++)
		vec.push_back(sum[3][i-1]-sum[2][i]),
		vec.push_back(sum[1][i]-sum[2][i-1]+sum[3][n]);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	tot=vec.size();

	t.clear();
	for (int i=n;i>=1;i--){
		int now=find_id(sum[3][i-1]-sum[2][i]);
		t.change(now,1);
		int qry=find_id(sum[1][i]-sum[2][i-1]+sum[3][n]);
		ans=(ans+t.query(qry))%tt;
	}
	printf("%lld\n",ans);
	return 0;
}