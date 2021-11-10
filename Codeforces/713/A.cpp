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

int t;
const int maxn=1LL<<20;
int cnt[maxn];

signed main(){
	t=read();
	while (t--){
		char ch=getchar(); while (ch!='+' && ch!='-' && ch!='?') ch=getchar();
		if (ch=='+'){
			int x=read();
			int p=1;
			for (int i=1;i<=18;i++){
				if ((x%10)&1) p=(p<<1)+1; else p=p<<1;
				x=x/10;
			}
			cnt[p]++;
		} else if (ch=='-'){
			int x=read();
			int p=1;
			for (int i=1;i<=18;i++){
				if ((x%10)&1) p=(p<<1)+1; else p=p<<1;
				x=x/10;
			}
			// if (cnt[p]<1) printf("ERROR!\n");
			cnt[p]--;
		} else if (ch=='?'){
			int x=read();
			int p=1;
			for (int i=1;i<=18;i++){
				if ((x%10)&1) p=(p<<1)+1; else p=p<<1;
				x=x/10;
			}
			printf("%lld\n",cnt[p]);
		}
	}
	return 0;
}