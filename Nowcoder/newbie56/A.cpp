#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
#define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int a,b,n;

signed main(){
    a=read(),b=read(),n=read();
    printf("%lld %lld\n",n,(a+b)*n);
    return 0;
}