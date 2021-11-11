// Totally WRONG!!!!

#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>

using namespace std;

// #define int long long

// inline int read(){
// 	int ret=0,f=1;char ch=getchar();
// 	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
// 	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
// 	return ret*f;
// }

// map<pair<pair<int,int>, pair<int,int> >, int> rcd;

int n;

int top1=-1,left1=-1,bot1=-1,right1=-1;
int top2=-1,left2=-1,bot2=-1,right2=-1;

int queryy(int x1,int y1,int x2,int y2){
	// if (rcd[make_pair(make_pair(x1,y1),make_pair(x2,y2))])
	// 	return rcd[make_pair(make_pair(x1,y1),make_pair(x2,y2))]-1;
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int x; scanf("%d",&x);
	// rcd[make_pair(make_pair(x1,y1),make_pair(x2,y2))]=x+1;
	return x;
}

signed main(){
	scanf("%d",&n);

	// Find top
	int l=1,r=n; bool flg=false;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		int now=queryy(1,1,mid,n);
		if (now==1) top1=mid,flg=true,r=mid-1; else
		if (now>1) {if (!flg) top1=mid; r=mid-1;} else l=mid+1;
	}
	l=1,r=n;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		int now=queryy(1,1,mid,n);
		if (now==2) top2=mid,r=mid-1;
		else l=mid+1;
	}

	// Find bot
	l=1,r=n;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		int now=queryy(mid,1,n,n);
		if (now==2) bot1=mid,l=mid+1;
		else r=mid-1;
	}
	l=1,r=n; flg=false;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		int now=queryy(mid,1,n,n);
		if (now==1) bot2=mid,flg=true,l=mid+1; else
		if (now>1) {if (!flg) bot2=mid; l=mid+1;} else r=mid-1;
	}

	// Find left
	l=1,r=n;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		int now=queryy(1,mid,n,n);
		if (now==2) left1=mid,l=mid+1;
		else r=mid-1;
	}
	l=1,r=n; flg=false;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		int now=queryy(1,mid,n,n);
		if (now==1) left2=mid,flg=true,l=mid+1; else
		if (now>1) {if (!flg) left2=mid; l=mid+1;} else r=mid-1;
	}

	// Find right
	l=1,r=n; flg=false;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		int now=queryy(1,1,n,mid);
		if (now==1) right1=mid,flg=true,r=mid-1; else
		if (now>1) {if (!flg) right1=mid; r=mid-1;} else l=mid+1;
	}
	l=1,r=n;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		int now=queryy(1,1,n,mid);
		if (now==2) right2=mid,r=mid-1;
		else l=mid+1;
	}

	if (queryy(bot1,left1,top1,right1)!=1 || queryy(bot2,left2,top2,right2)!=1)
		swap(left1,left2),swap(right1,right2);
	printf("! %d %d %d %d %d %d %d %d\n",bot1,left1,top1,right1,bot2,left2,top2,right2);
	fflush(stdout);
	return 0;
}

// 一个反例：
// 10
// 1 1 10 1
//  5 5 5 10