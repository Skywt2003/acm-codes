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
int cnt[4],ccnt[4],rep[4];
int ans=0;

void build_jc(){
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%tt;
}

inline int qsm(int a,int b){
	int w=a%tt,ret=1;
	while (b){
		if (b&1) ret=ret*w%tt;
		b>>=1; w=w*w%tt;
	}
	return ret;
}

signed main(){
	build_jc();

	n=read();
	scanf("%s",&s);
	for (int i=0;i<n;i++){
		if (s[i]=='A') cnt[0]++; else
		if (s[i]=='C') cnt[1]++; else
		if (s[i]=='G') cnt[2]++; else
		if (s[i]=='T') cnt[3]++;
	}
	for (int i=0;i<4;i++) ccnt[i]=cnt[i];

	rep[0]=rep[1]=rep[2]=rep[3]=1;
	for (int i=0;i<4;i++) if (ccnt[i])
		for (int j=i+1;j<4;j++)
			if (cnt[i]==cnt[j])
				ccnt[i]+=cnt[j],rep[i]++,cnt[j]=ccnt[j]=0;

	ans=jc[n];
	for (int i=0;i<4;i++) if (ccnt[i])
		ans=ans*qsm(jc[ccnt[i]],tt-2)%tt*qsm(rep[i],ccnt[i])%tt;

	printf("%lld\n",ans);
	return 0;
}