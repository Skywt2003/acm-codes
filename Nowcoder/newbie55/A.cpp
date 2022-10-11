#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int x,y;

signed main(){
    x=read(),y=read();
    printf("%d\n",y + (y-x));
    return 0;
}