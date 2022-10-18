#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=4e6+5;
const int N=4e6+1;

int n,q;

int prime[maxn];
int a[maxn];

bool vis[maxn];

map<int,bool> hav;

void build_prime(){
    memset(vis,true,sizeof(vis));
    vis[1]=false;
    for (int i=2;i<=N;i++){
        if (vis[i]) prime[++prime[0]]=i;
        for (int j=1;j<=prime[0];j++){
            if (i*prime[j] > N) break;
            vis[i*prime[j]] = false;
            if (i%prime[j] == 0) break;
        }
    }
}

signed main(){
    n=read(),q=read();
    build_prime();
    // printf("%d\n",prime[0]);
    int now_ans=1;
    for (int i=1;i<=n;i++){
        int now=read();
        hav[now]=true;
        while (hav[prime[now_ans]]) now_ans++;
        a[i]=prime[now_ans];
    }
    while (q--){
        int now=read();
        printf("%d\n",a[now]);
    }
    return 0;
}