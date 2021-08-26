#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1005,N=999;
int t,n;
int a[maxn];

bool check_sort(){
	for (int i=1;i<n;i++) if (a[i]>a[i+1]) return false;
	return true;
}

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();

		if (check_sort()) {printf("0\n");continue;}
		for (int i=1;i<=n+5;i++){
			if (i&1){
				for (int j=1;j<n;j+=2) if (a[j]>a[j+1]) swap(a[j],a[j+1]);
			} else {
				for (int j=2;j<n;j+=2) if (a[j]>a[j+1]) swap(a[j],a[j+1]);
			}
			if (check_sort()) {printf("%lld\n",i);break;}
		}
	}
	return 0;
}