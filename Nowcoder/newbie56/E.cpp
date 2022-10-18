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

const int maxn=2e5+5;

int n,k;
char a[maxn];

vector<int> vec;
int ans=0;

signed main(){
    n=read(),k=read();
    scanf("%s",a+1);
    bool had_Z=false;
    for (int i=1;i<=n;i++){
        if (a[i] == 'Z'){
            had_Z=true;
            if (i>1 && a[i-1]=='Z') ans+=4;
            continue;
        }
        if (!had_Z) continue;
        int j=i;
        while (j+1<=n && a[j+1]=='z') j++;
        if (j==n && a[j]=='z') break;
        vec.push_back(j-i+1);
        i=j;
    }
    sort(vec.begin(),vec.end());
    for (int i=0;i<vec.size();i++){
        if (k-vec[i] < 0) break;
        ans+=4; k-=vec[i];
    }
    printf("%d\n",ans);
    return 0;
}