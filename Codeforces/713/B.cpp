#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

int n;

int queryy(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int x; scanf("%d",&x);
	return x;
}

int divn=-1; // where it broke
bool divx=false; // -------

vector<int> vec;

void make_answer(int x1,int y1,int x2,int y2){
	int top=-1,left=-1,bot=-1,right=-1;

	// Find top
	int l=x1,r=x2;
	while (l<=r){
		int mid=((r-l)>>1)+l,now=queryy(x1,y1,mid,y2);
		if (now==1) top=mid,r=mid-1; else l=mid+1;
	}
	// Find bot
	l=x1,r=x2;
	while (l<=r){
		int mid=((r-l)>>1)+l,now=queryy(mid,y1,x2,y2);
		if (now==1) bot=mid,l=mid+1; else r=mid-1;
	}
	// Find left
	l=y1,r=y2;
	while (l<=r){
		int mid=((r-l)>>1)+l,now=queryy(x1,mid,x2,y2);
		if (now==1) left=mid,l=mid+1; else r=mid-1;
	}
	// Find right
	l=y1,r=y2;
	while (l<=r){
		int mid=((r-l)>>1)+l,now=queryy(x1,y1,x2,mid);
		if (now==1) right=mid,r=mid-1; else l=mid+1;
	}

	vec.push_back(bot);
	vec.push_back(left);
	vec.push_back(top);
	vec.push_back(right);

}

signed main(){
	scanf("%d",&n);

	int l=1,r=n-1;
	while (l<=r){
		int mid=((r-l)>>1)+l;
		int x=queryy(1,1,mid,n),y=queryy(mid+1,1,n,n);
		if (x==1 && y==1){ divn=mid;divx=true;break; } else
		if (x==0 && y==0){ divx=false; break; } else
		if (x>y) r=mid-1; else l=mid+1;
	}
	if (!divx){
		l=1,r=n-1;
		while (l<=r){
			int mid=((r-l)>>1)+l;
			int x=queryy(1,1,n,mid),y=queryy(1,mid+1,n,n);
			if (x==1 && y==1){ divn=mid; break; } else
			// if (x==0 && y==0){ printf("ERROR!!!\n"); } else
			if (x>y) r=mid-1; else l=mid+1;
		}
		make_answer(1,1,n,divn);
		make_answer(1,divn+1,n,n);
	} else {
		make_answer(1,1,divn,n);
		make_answer(divn+1,1,n,n);
	}
	printf("! "); for (int i=0;i<8;i++) printf("%d ",vec[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}