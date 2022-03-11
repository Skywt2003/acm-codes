#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

// #define int long long

// inline int read(){
// 	int ret=0,f=1; char ch=getchar();
// 	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
// 	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
// 	return ret*f;
// }

int t,n;

int i,j,lk;

int query(int x,int y,int z){
	printf("? %d %d %d\n",x,y,z); fflush(stdout);
	// int ret=read();
	int ret; scanf("%d",&ret);
	if (ret==-1) exit(-1);
	return ret;
}

signed main(){
	// t=read();
	scanf("%d",&t);
	while (t--){
		// n=read();
		scanf("%d",&n);
		int tmp1=query(1,2,3),tmp2=query(1,2,4),tmp3=query(1,3,4),tmp4=query(2,3,4);
		int last_query;
		if (tmp1==tmp2 && tmp3==tmp4){
			if (tmp1>tmp3) tmp4=-1; else tmp2=-1;
		} else if (tmp1==tmp3 && tmp2==tmp4){
			if (tmp1>tmp2) tmp4=-1; else tmp3=-1;
		}
		if (tmp1==tmp2) i=1,j=2,lk=3,last_query=tmp1; else
		if (tmp1==tmp3) i=1,j=3,lk=2,last_query=tmp1; else
		if (tmp1==tmp4) i=2,j=3,lk=1,last_query=tmp1; else
		if (tmp2==tmp3) i=1,j=4,lk=2,last_query=tmp2; else 
		if (tmp2==tmp4) i=2,j=4,lk=1,last_query=tmp2; else
		if (tmp3==tmp4) i=3,j=4,lk=1,last_query=tmp3;

		for (int k=5;k<=n;k++){
			int now=query(i,j,k);
			if (now != last_query){
				if (now < last_query) exit(-1);
				int tmp1=query(i,lk,k);
				if (tmp1==now) lk=j,j=k; else lk=i,i=k;
				last_query = now;
			}
		}

		printf("! %d %d\n",i,j); fflush(stdout);
	}
	return 0;
}