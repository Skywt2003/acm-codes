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

const int maxn=2e5+5;

int t;
int n;
int a[maxn];
int data[maxn];

bool check_answer(int x){
	for (int i=1;i<=n;i++) a[i]=data[i];
	for (int i=3;i<n;i++){
		int delta = std::max(0,x-a[i-2]+1)/2; // 优先补 i-2
		delta = std::max(delta, (a[i]-x)/3); // 如果 i 有富余，全部投入
		int next_d = std::max(0,x-(a[i-1]+delta)+1)/2; // i+1 需要投入补 i-1 的 d
		if (next_d*3 > a[i+1]) // i+1 补不起，尽力而为，i 来补 i-1
			next_d=a[i+1]/3,
			delta=std::max(delta,x-(a[i-1]+next_d*2));
			// delta = std::max(delta,a[i]/3);
		if (delta*3 > a[i]) return false; // 这样补不起
		a[i]-=delta*3;
		a[i-1]+=delta;
		a[i-2]+=delta*2;
	}
	int final_d = (a[n]-x)/3;
	if (a[n-2]+final_d*2 < x || a[n-1]+final_d < x) return false;
	return true;
}

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) data[i]=read();
		int l=1,r=data[n];
		int ans=1;
		while (l<=r){
			int mid=((r-l)>>1)+l;
			if (check_answer(mid)) ans=mid,l=mid+1; else r=mid-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}