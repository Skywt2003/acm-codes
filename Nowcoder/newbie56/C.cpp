#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
// #define int long long

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2e5+5;

int n;
pair<int,int> a[maxn];

vector<int> vec[10];

int lft;

signed main(){
    n=read();
    for (int i=1;i<=n;i++) a[i].first=-read(),a[i].second=i;
    sort(a+1,a+1+n);

    lft = n%10;
    int now_num = n/10;
    int cnt=1;
    for (int i=9;i>=0;i--){
        if (i == lft) now_num++;
        if (i == 0) now_num--;
        for (int j=0;j<now_num;j++) vec[i].push_back(-a[cnt++].first);
    }
    vec[0].push_back(-1);
    for (int i=0;i<10;i++) reverse(vec[i].begin(),vec[i].end());
    // for (int i=0;i<10;i++){
    //     printf("vec[%d]: ",i);
    //     for (int j=0;j<vec[i].size();j++) printf("%d ",vec[i][j]);
    //     printf("\n");
    // }
    for (int i=0;i<n/10+1;i++){
        for (int j=0;j<10;j++){
            if (i == vec[j].size()) break;
            if (vec[j][i] == -1) continue;
            printf("%d ",vec[j][i]);
        }
    }
    printf("\n");
    return 0;
}