#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn=1005,maxs=55;

int n,L,S;
pair<int,int> a[maxn];
int b[maxs][maxs];
int c[maxn][maxn];

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int ans=0;

signed main(){
    n=read(),L=read(),S=read();
    for (int i=1;i<=n;i++) a[i].first=read(),a[i].second=read();
    for (int i=S;i>=0;i--)
        for (int j=0;j<=S;j++)
            b[i][j]=read();
    for (int i=1;i<=n;i++) if (a[i].first+S <= L && a[i].second+S <= L){
        memset(c,0,sizeof(c));
        bool now_ans = true;
        for (int j=1;j<=n;j++)
            if (a[i].first <= a[j].first && a[j].first <= a[i].first+S
            && a[i].second <= a[j].second && a[j].second <= a[i].second+S){
                int xx=a[j].first-a[i].first,yy=a[j].second-a[i].second;
                if (c[xx][yy]) {now_ans=false; break;}
                if (!b[xx][yy]) {now_ans=false; break;}
                c[xx][yy]++;
            }
        for (int ii=0;ii<=S && now_ans;ii++)
            for (int jj=0;jj<=S && now_ans;jj++)
                if (b[ii][jj] && !c[ii][jj]) now_ans=false;
        ans+=now_ans;
    }
    cout<<ans<<endl;
    return 0;
}