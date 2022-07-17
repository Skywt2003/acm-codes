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
char a[maxn];

signed main(){
    t=read();
    while (t--){
        n=read();
        scanf("%s",a+1);
        int ans=0;
        for (int i=1;i<=n;i++){
            ans++;
            if ((a[i]=='0' && a[i+1]=='1') || (a[i]=='1' && a[i+1]=='0'))
                ans+=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}