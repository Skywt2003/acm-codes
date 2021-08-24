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

int n;
char s[4],s1[4];
int max_h=0,ans=0;
int acgt[4] = {'A','C','G','T'};

int get_h(){
	int ret=0;
	for (int i=0;i<4;i++)
		for  (int j=0;j<4;j++) if (s[i]==s1[j])
			ret+=4;
	return ret;
}

signed main(){
	n=read();
	scanf("%s",&s);
	for (int i1=0;i1<4;i1++)
		for (int i2=0;i2<4;i2++)
			for (int i3=0;i3<4;i3++)
				for (int i4=0;i4<4;i4++){
					s1[0]=acgt[i1]; s1[1]=acgt[i2];
					s1[2]=acgt[i3]; s1[3]=acgt[i4];
					int now=get_h();
					if (now>max_h) max_h=now,ans=1; else
					if (now==max_h) ans++;
				}
	printf("%lld\n",ans);
	printf("MAX: %lld\n",max_h);
	return 0;
}