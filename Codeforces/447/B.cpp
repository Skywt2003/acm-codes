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

const int maxn=1005;

char s[maxn];
int k,n;
int w[30];
int ans=0,wmax=0;

signed main(){
	scanf("%s",&s); n=strlen(s);
	k=read();
	for (int i=0;i<26;i++) w[i]=read(),wmax=max(wmax,w[i]);
	for (int i=0;i<n;i++) ans=ans+(i+1)*w[s[i]-'a'];
	for (int i=n;i<n+k;i++) ans=ans+(i+1)*wmax;
	printf("%lld\n",ans);
	return 0;
}