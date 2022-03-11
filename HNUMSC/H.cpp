#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<vector>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=1e6+5;

int n,k;

void print(int x){
	if (x<10) printf("%d",x);
	else putchar(x-10+'A');
}

void print_num(){
	std::vector<int> vec; vec.clear();
	while (n){
		int yu=n%k; n/=k;
		if (yu<0) yu+=abs(k),n++;
		vec.push_back(yu);
	}
	reverse(vec.begin(),vec.end());
	for (int i=0;i<vec.size();i++) print(vec[i]);
}

signed main(){
	n=read(),k=read();
	printf("%d=",n);
	print_num();
	printf("(base%d)\n",k);
	return 0;
}
