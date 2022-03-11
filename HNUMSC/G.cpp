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

const int maxn=100005;

int n;

std::pair<int,int> a[maxn];

bool cmp(std::pair<int,int> aa,std::pair<int,int> bb){
	return aa.second > bb.second;
}

int ans=0;

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=std::make_pair(i,read());

	sort(a+1,a+1+n,cmp);
	int left=a[1].first,right=a[1].first;
	for (int i=1;i<=n;i++){
		left=std::min(left,a[i].first);
		right=std::max(right,a[i].first);
		int j=i;
		while (j+1<=n && a[j+1].second == a[i].second){
			j++;
			left=std::min(left,a[j].first);
			right=std::max(right,a[j].first);
		}
		for (int k=i;k<=j;k++){
			ans=std::max(ans,a[k].second*(right-a[k].first));
			ans=std::max(ans,a[k].second*(a[k].first-left));
		}
		i=j;
	}
	printf("%d\n",ans);
	return 0;
}