#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long

inline int read(){
    int ret=0ll,f=1ll;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1ll;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1e5+5;
const int N=1e5;
const int tt=1e9+7;

int T,n,nn[maxn];
int fa[maxn];
int frac[maxn];
int inv[maxn];
vector<int> sons[maxn];
int sum[maxn];

int qsm(int a,int b){
    int ret=1,w=a%tt;
    while (b){
        if (b&1) ret=ret*w%tt;
        w=w*w%tt; b>>=1;
    }
    return ret;
}

void build_frac(){
    frac[0]=1;
    for (int i=1;i<=N;i++) frac[i]=frac[i-1]*i%tt;
    inv[N] = qsm(frac[N],tt-2);
    for (int i=N-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%tt;
}

void build_sum(int x){
    sum[x]=1;
    for (int i=0;i<sons[x].size();i++) build_sum(sons[x][i]),sum[x]+=sum[sons[x][i]];
}

int get_answer(int x){
    if (sons[x].size() == 0) return 1;
    int ret=frac[sum[x]-1];
    for (int i=0;i<sons[x].size();i++){
        int now = get_answer(sons[x][i]);
        ret = ret * now %tt * inv[sum[sons[x][i]]] %tt;
    }
    return ret;
}

void clear_data(){
    for (int i=1;i<=n;i++) sons[i].clear(),sum[i]=0;
}

vector<int> vec;

signed main(){
    build_frac();
    T=read();
    int cc=0;
    while (T--){
        clear_data();
        n=read();  nn[cc++]=n;
        for (int i=2;i<=n;i++) fa[i]=read(),sons[fa[i]].push_back(i);
        build_sum(1);
        vec.push_back(get_answer(1));
    }
    int all_sum=0;
    for (int i=0;i<vec.size();i++) all_sum+=nn[i];
    int all_ans = frac[all_sum];
    for (int i=0;i<vec.size();i++) all_ans = all_ans * vec[i] %tt * inv[nn[i]] %tt;
    printf("%lld\n",all_ans);
    return 0;
}