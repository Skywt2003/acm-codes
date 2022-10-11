#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// #define int long long

inline int read(){
    int ret=0ll,f=1ll;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1ll;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

const int maxn=2e5+5;

int T,n;
vector<int> vec[maxn];
vector<pair<int,int> > ans;

void clear_data(){
    for (int i=0;i<n;i++) vec[i].clear();
    ans.clear();
}


signed main(){
    T=read();
    while (T--){
        clear_data();
        n=read();
        for (int i=1;i<=n;i++){
            int x=read();
            vec[x].push_back(i);
        }
        int cnt=vec[0].size();
        if (cnt == n){
            if (n == 1) printf("1\n");
            else printf("-1\n");
            continue;
        }

        int root = -1;
        for (int i=1;i<n;i++){
            if (cnt + vec[i].size() == n){
                if (vec[i].size() > 1) break;
                root = vec[i][0];
                for (int j=0;j<vec[i-1].size();j++) ans.push_back(make_pair(root,vec[i-1][j]));
                break;
            }
            if (vec[i].size() == 0 || vec[i].size() > vec[i-1].size()) break;
            for (int j=0;j<vec[i].size();j++) ans.push_back(make_pair(vec[i][j],vec[i-1][j]));
            for (int j=0;j<vec[i-1].size()-vec[i].size();j++) ans.push_back(make_pair(vec[i][vec[i].size()-1], vec[i-1][vec[i].size()+j]));
            cnt += vec[i].size();
        }
        if (root == -1){
            printf("-1\n");
        } else {
            printf("%d\n",root);
            for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
    return 0;
}