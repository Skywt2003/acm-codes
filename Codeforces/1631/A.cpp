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

const int maxn=105;

int t;
int n;
int a[maxn],b[maxn];

signed main(){
	t=read();
	while (t--){
		n=read();
		int max_num=-1,max_pos=-1;
		for (int i=1;i<=n;i++){
			a[i]=read();
			if (a[i]>max_num) max_num=a[i],max_pos=i;
		}
		for (int i=1;i<=n;i++){
			b[i]=read();
			if (b[i]>max_num) max_num=b[i],max_pos=n+i;
		}

		if (max_pos > n) std::swap(a[max_pos-n], b[max_pos-n]), max_pos-=n;
		for (int i=1;i<=n;i++) if (i!=max_pos && a[i]<b[i]) std::swap(a[i],b[i]);
		int scd_num = -1;
		for (int i=1;i<=n;i++) scd_num=std::max(scd_num,b[i]);
		printf("%d\n",max_num*scd_num);
	}
	return 0;
}