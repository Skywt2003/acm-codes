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

const int maxn=105;

int t;
int n;
char s[maxn];
int ans;

signed main(){
	t=read();
	while (t--){
		n=read(); ans=0;
		scanf("%s",s);
		for (int i=0;i<n;i++){
			ans+=s[i]-'0';
			if (s[i]!='0' && i!=n-1) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}