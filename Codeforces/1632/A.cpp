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

int t,n;
char s[maxn];

signed main(){
	t=read();
	while (t--){
		n=read();
		scanf("%s",s+1);
		if (n>2 || (n==2 && s[1]==s[2])) printf("NO\n");
		 else printf("YES\n");
	}
	return 0;
}