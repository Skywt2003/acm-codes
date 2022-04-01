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

int t,n;

signed main(){
	t=read();
	while (t--){
		n=read();
		if (n%3 == 1){
			for (int i=1;i<=n/3*2+1;i++) putchar((i&1)?'1':'2');
		} else if (n%3 == 2){
			for (int i=1;i<=n/3*2+1;i++) putchar((i&1)?'2':'1');
		} else {
			for (int i=1;i<=(n-1)/3*2+2;i++) putchar((i&1)?'2':'1');
		}
		printf("\n");
	}
}
