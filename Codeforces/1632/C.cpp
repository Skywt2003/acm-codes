#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;

int t,a,b;
int ans;

signed main(){
	t=read();
	while (t--){
		a=read(),b=read();
		if (a>=b) printf("%d\n",a-b);
		else {
			ans=b-a;
			int aa=a,bb=b;
			if (((aa|b) == b) || ((a|bb) == bb)) ans=1;
			for (int i=1;i<=ans-2;i++){
				aa++; bb++;
				if (((aa|b) == b) || ((a|bb) == bb)) {ans=i+1;break;}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}