#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<vector>
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

int n;
int a[maxn],f[maxn],cnt[maxn];
int ans=0;

std::priority_queue<std::pair<int,int> > heap;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++;

	heap.push(std::make_pair(-2,a[1])); cnt[a[1]]--;
	for (int i=2;i<=n;i++){
		while (!heap.empty() && !cnt[heap.top().second]) heap.pop();
		if (heap.empty()) f[i]=0; else f[i]=heap.top().first+i;
		f[i]=std::max(f[i],f[i-1]);
		ans=std::max(ans,f[i]);
		cnt[a[i]]--;
		heap.push(std::make_pair(f[i]-i-1,a[i]));
		// printf("f[%d] = %d\n",i,f[i]);
	}

	printf("%d\n",ans);
	return 0;
}