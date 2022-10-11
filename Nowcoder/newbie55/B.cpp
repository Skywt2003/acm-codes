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

int x,y;
int ans=0ll;

signed main(){
    x=read(),y=read();
    for (int i=0;i<63;i++){
        int xx = x & (1ll << i);
        int yy = y & (1ll << i);
        if (!(xx ^ yy)) ans += 1ll << i;
    }
    printf("%lld\n",ans);
    return 0;
}