#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<vector>
#include<map>
#include<ctime>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int n,k;

signed main(){
	srand(time(NULL));
	n=rand()%2000; k=rand()%2000;
	printf("%d %d\n",n,k);
	for (int i=1;i<=k;i++){
		int x=rand()%n+1,y=rand()%n+1;
		if (x>y) std::swap(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}