#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e5+5,N=1e5;
const int tt=1e9+7;

int jc[maxn];

int n;
char s[maxn];
int cnt[4];

inline int qsm(int a,int b){
	int w=a%tt,ret=1;
	while (b){
		if (b&1) ret=ret*w%tt;
		b>>=1; w=w*w%tt;
	}
	return ret;
}

signed main(){
	n=read();
	scanf("%s",&s);
	for (int i=0;i<n;i++){
		if (s[i]=='A') cnt[0]++; else
		if (s[i]=='C') cnt[1]++; else
		if (s[i]=='G') cnt[2]++; else
		if (s[i]=='T') cnt[3]++;
	}
	
	int max_cnt=0,cnt_cnt=0;
	for (int i=0;i<4;i++){
		if (cnt[i]>max_cnt) max_cnt=cnt[i],cnt_cnt=1; else
		if (cnt[i]==max_cnt) cnt_cnt++;
	}

	printf("%lld\n",(max_cnt==1)?qsm(n,n):qsm(cnt_cnt,n));
	return 0;
}