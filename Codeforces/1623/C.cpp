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
	for (int i=n;i>=3;i--){
		if (a[i]<x) return false;
		int delta = std::min(data[i],a[i]-x)/3;
		a[i]-=delta*3;
		a[i-1]+=delta; a[i-2]+=delta*2;
	}
	return a[1]>=x && a[2]>=x;
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