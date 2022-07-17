#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

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
int fa[maxn],l[maxn],r[maxn];
int a[maxn];
int ans=0;

vector<int> sons[maxn];

void DFS(int x){
    int sum=0;
    for (int i=0;i<(int)sons[x].size();i++)
        DFS(sons[x][i]),sum+=a[sons[x][i]];
    if (sum < l[x]) ans++, a[x]=r[x];
    else a[x]=min(r[x],a[x]+sum);
}

signed main(){
    t=read();
    while (t--){
        n=read();
        ans=0;
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++) sons[i].clear();

        for (int i=2;i<=n;i++) fa[i]=read(),sons[fa[i]].push_back(i);
        for (int i=1;i<=n;i++) l[i]=read(),r[i]=read();
        DFS(1);
        printf("%lld\n",ans);
    }
    return 0;
}