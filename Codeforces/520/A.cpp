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

int n;
char s[maxn];
int cnt[30];

signed main(){
	n=read();
	scanf("%s",&s);
	for (int i=0;i<n;i++){
		if (s[i]>='a' && s[i]<='z') cnt[s[i]-'a']++;
		else cnt[s[i]-'A']++;
	}
	int ans=true;
	for (int i=0;i<26;i++) if (cnt[i]==0) ans=false;
	printf(ans?"YES\n":"NO\n");
	return 0;
}