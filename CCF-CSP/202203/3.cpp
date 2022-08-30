// 纯粹的模拟 + 用 std::map 优化

#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=1005;

int n,m,t;

int area[maxn];

// bool f[maxn][maxn];
// bool g[maxn][maxn];

map<int,bool> f[maxn]; // f[i][j]: i 节点所在可用区是否包含 j 应用
map<int,bool> g[maxn]; // g[i][j]: i 节点是否包含 j 应用

int cnt[maxn]; // 各个节点运行任务数量

bool vis[maxn];

signed main(){
    n=read(),m=read();
    for (int i=1;i<=n;i++) area[i]=read();
    t=read();
    while (t--){
        int ff=read(),app=read();
        int need_area=read();
        int need_app=read(); // 必须与应用在一个可用区
        int dont_app=read(),must=read(); // 不得与应用在同一个节点
        while (ff--){
            memset(vis,true,sizeof(vis));
            int tot=n;
            if (need_area){
                for (int i=1;i<=n;i++)
                    if (vis[i] && area[i] != need_area) vis[i]=false,tot--;
            }
            if (need_app){
                for (int i=1;i<=n;i++)
                    if (vis[i] && !f[i][need_app]) vis[i]=false,tot--;
            }
            if (dont_app){
                int tmp=tot;
                for (int i=1;i<=n;i++)
                    if (g[i][dont_app] && vis[i]) tmp--;
                if (tmp!=0 || must){
                    for (int i=1;i<=n;i++)
                        if (g[i][dont_app] && vis[i]) vis[i]=false,tot--;
                }
            }
            vector<pair<int,int> > vec; vec.clear();
            for (int i=1;i<=n;i++)
                if (vis[i]) vec.push_back(make_pair(cnt[i],i));
            sort(vec.begin(),vec.end());
            if (vec.size() == 0){
                printf("0 ");
            } else {
                int ans=vec[0].second;
                printf("%d ",ans);
                cnt[ans]++;
                for (int i=1;i<=n;i++) if (area[i]==area[ans]) f[i][app]=true;
                g[ans][app]=true;
            }
        }
        printf("\n");
    }
    return 0;
}