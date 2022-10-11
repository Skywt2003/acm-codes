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

const int maxn=105;
const int N=88;

int fib[maxn];

void build_fib(){
    fib[1] = 1;
    fib[2] = 1;
    for (int i=3;i<=N;i++){
        fib[i]=fib[i-1]+fib[i-2];
        // if (fib[i] > 1e18) printf("OK %lld\n",i);
    }
}

int bin_find(int x){
    int l=1,r=88;
    int ret=((r-l)>>1)+l;
    while (l <= r){
        int mid = ((r-l)>>1)+l;
        if (abs(fib[mid]-x) < abs(fib[ret]-x) || 
            (abs(fib[mid]-x) == abs(fib[ret]-x)) && mid < ret )
            ret = mid;
        if (fib[mid] < x) l=mid+1;
        else r=mid-1;
    }
    return ret;
}

signed main(){
    build_fib();
    int T=read();
    while (T--){
        int x=read();
        printf("%lld\n",bin_find(x));
    }
    return 0;
}