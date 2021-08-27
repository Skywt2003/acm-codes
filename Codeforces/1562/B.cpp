#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e4+5;

int t;
int k;
char s[maxn];

int dig[15];
bool prt;

int prime[10000];

bool is_prime(int x){
	if (prime[x]!=-1) return prime[x];
	prime[x]=1;
	for (int i=2;i<=sqrt(x);i++) if (x%i==0){
		prime[x]=0; break;
	}
	return prime[x];
}

int pop_count(int x){
	int ret=0;
	while (x) ret++,x=x/10;
	return ret;
}

signed main(){
	memset(prime,-1,sizeof(prime));
	prime[1]=false; prime[2]=true;

	t=read();
	while (t--){
		memset(dig,0,sizeof(dig));

		k=read();
		scanf("%s",s+1); prt=false;
		for (int i=1;i<=k;i++)
			if (s[i]=='1'||s[i]=='4'||s[i]=='6'||s[i]=='8'||s[i]=='9'){
				printf("1\n%c\n",s[i]); prt=true;
				break;
			}

		if (prt) continue;
		for (int i=1;i<=k;i++){
			dig[s[i]-'0']++;
			if (dig[s[i]-'0'] > 1){
				printf("2\n%c%c\n",s[i],s[i]); prt=true;
				break;
			}
		}
		if (prt) continue;

		int ans1=k+1,ans2=-1;
		for (int i=1;i<(1<<k);i++){
			int now=0;
			for (int j=0;j<k;j++) if (i&(1<<j)) now=now*10+s[j+1]-'0';
			if ((is_prime(now)==false) && (pop_count(now)<ans1)) ans1=pop_count(now),ans2=now; 
		}
		printf("%lld\n%lld\n",ans1,ans2);
	}
	return 0;
}