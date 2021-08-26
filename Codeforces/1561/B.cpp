#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int t;
int a,b,n;
int nowa,nowb,now,lft;

vector<int> ans;

signed main(){
	t=read();
	while (t--){
		ans.clear();
		a=read();b=read(); n=a+b;
		if (n&1){
			nowa=(n+1)/2; nowb=n/2;
			if (a>nowa) now=a-nowa; else now=b-nowb;
			lft=min(n-a,n-b);
			ans.push_back(now);
			while (lft--) now+=2,ans.push_back(now);

			nowa=n/2; nowb=(n+1)/2;
			if (a>nowa) now=a-nowa; else now=b-nowb;
			lft=min(n-a,n-b);
			ans.push_back(now);
			while (lft--) now+=2,ans.push_back(now);
		} else {
			nowa=n/2; nowb=n/2;
			if (a>nowa) now=a-nowa; else now=b-nowb;
			lft=min(n-a,n-b);
			ans.push_back(now);
			while (lft--) now+=2,ans.push_back(now);
		}
		sort(ans.begin(),ans.end());
		printf("%lld\n",(int)ans.size());
		for (int i=0;i<ans.size();i++) printf("%lld ",ans[i]);printf("\n");
	}
	return 0;
}