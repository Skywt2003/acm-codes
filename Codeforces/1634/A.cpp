#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=105;

int t,n,k;

char s[maxn];

bool is_reverse(){
	for (int i=1;i<=n/2;i++) if (s[i]!=s[n-i+1]) return false;
	return true;
}

signed main(){
	t=read();
	while (t--){
		n=read(),k=read();
		scanf("%s",s+1);
		if (k==0 || is_reverse()) printf("1\n"); else printf("2\n");
	}
}