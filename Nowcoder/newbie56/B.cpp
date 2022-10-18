#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int m;

signed main(){
    m=read();
    if (m==1){
        printf("1\n1\n");
        return 0;
    }
    printf("2\n");
    for (int i=1;i<=m;i++) printf("1\n");
    return 0;
}