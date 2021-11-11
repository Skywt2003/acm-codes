#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

priority_queue<int,vector<int>,greater<int> > heap1; // min root
priority_queue<int> heap2; // max root
int sum1=0,sum2=0;

const int maxn=3005;
// const int INF=1LL<<60;
const int INF=0x3f3f3f3f3f3f3f3f;

int n;
int a[maxn];
int delta[maxn][maxn];
int mid[maxn][maxn];
int f[maxn],last[maxn];

signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	
	for (int i=1;i<=n;i++){
		while (!heap1.empty()) heap1.pop();
		while (!heap2.empty()) heap2.pop();
		sum1=sum2=0;
		for (int j=i;j<=n;j++){
			int now=a[j]-(j-i+1);
			if (heap1.empty()) heap1.push(now),sum1+=now; else
			if (heap1.size()==heap2.size()){
				if (now<heap2.top())
					heap1.push(heap2.top()),sum1+=heap2.top(),
					sum2-=heap2.top(),heap2.pop(),
					heap2.push(now),sum2+=now;
				else heap1.push(now),sum1+=now;
			} else {
				if (now>heap1.top())
					heap2.push(heap1.top()),sum2+=heap1.top(),
					sum1-=heap1.top(),heap1.pop(),
					heap1.push(now),sum1+=now;
				else heap2.push(now),sum2+=now;
			}
			mid[i][j]=heap1.top();
			delta[i][j]=(sum1-mid[i][j]*heap1.size()) + (mid[i][j]*heap2.size() - sum2);
			// printf("mid,delta[%lld,%lld] = %lld %lld\n",i,j,mid[i][j],delta[i][j]);
		}
	}

	memset(f,0x3f,sizeof(f));
	last[0]=-INF; f[0]=0;
	for (int i=0;i<=n;i++){
		for (int j=i+1;j<=n;j++) if (mid[i+1][j]+1 > last[i]){
			if (f[j] > f[i]+delta[i+1][j]) f[j]=f[i]+delta[i+1][j],last[j]=mid[i+1][j]+(j-i+1);
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}