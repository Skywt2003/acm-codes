#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
#define int long long

inline int read(){
    int ret=0ll,f=1ll;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1ll;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1e6+6;
int n,sum=0;

signed main(){
    n=read();
    for (int i=1;i<=n;i++){
        int x=read();
        sum+=x-i;
    }
    printf((sum&1)?"ZZZ\n":"SSZ\n");
    return 0;
}