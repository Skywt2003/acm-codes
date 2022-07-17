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

#define int long long

const int maxn=2e5+5;

int t;
int n;
int a[maxn];

signed main(){
    t=read();
    while (t--){
        n=read();
        for (int i=1;i<=n;i++) a[i]=read();
        int sum=0;
        bool ended=false,ans=true;
        for (int i=1;i<=n;i++){
            if (ended && a[i]) {ans=false;break;}
            sum+=a[i];
            if (sum<=0) ended=true;
        }
        if (sum) ans=false;
        printf(ans?"Yes\n":"No\n");
    }
    return 0;
}