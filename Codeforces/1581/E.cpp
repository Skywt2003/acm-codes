// UNAC

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

// #define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5,sqrtmaxn=450;

int n,m,x[maxn],y[maxn];
int num[sqrtmaxn][maxn],flg[maxn],rcd[maxn];
int mid;

signed main(){
	n=read(); m=read(); mid=sqrt(m);
	for (int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	int cnt=0;
	for (int i=1;i<=m;i++){
		int opt=read(),now=read();
		int cyc=x[now]+y[now];
		if (opt==1){
			rcd[now]=i;
			if (cyc > mid){
				int t=i+x[now];
				while (t<=m) {flg[t]++,flg[t+y[now]]--; t+=cyc;}
			} else {
				for (int j=x[now]+1;j<=x[now]+y[now];j++) num[cyc][(i+j-1)%cyc]++;
			}
		} else {
			if (cyc > mid){
				int t=rcd[now]+x[now];
				while (t<=m) {
					flg[t]--,flg[t+y[now]]++;
					if (t<i && i<t+y[now]) cnt--; // 不能直接删除维修完成的标记，需要额外判断
					// 还要考虑如果刚好这天进入维修的要移除就干脆不增加
					t+=cyc;
				}
			} else {
				for (int j=x[now]+1;j<=x[now]+y[now];j++) num[cyc][(rcd[now]+j-1)%cyc]--;
			}
		}
		cnt+=flg[i];
		int extra=0;
		for (int j=1;j<=mid;j++) extra+=num[j][i%j];
		printf("%d\n",cnt+extra);
	}
	return 0;
}