#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long 

const int maxn=1005*2;

const int tt=929;

int n,w,s,k;
char a[maxn];

vector<int> dat;
vector<int> d;
int g[maxn],q[maxn],xd[maxn],r[maxn];

int get_type(char ch){
    if ('A'<=ch && ch<='Z') return 0; else
    if ('a'<=ch && ch<='z') return 1; else
    if ('0'<=ch && ch<='9') return 2; else
    printf("ERROR");
    return 0;
}

void change_mode(int x,int y){
    if (x==y) return;
    if (x==0){
        if (y==1) dat.push_back(27); else
        if (y==2) dat.push_back(28);
    } else if (x==1){
        if (y==0) dat.push_back(28),dat.push_back(28); else
        if (y==2) dat.push_back(28);
    } else if (x==2){
        if (y==0) dat.push_back(28); else
        if (y==1) dat.push_back(27);
    }
}

int get_code(char ch){
    if ('A'<=ch && ch<='Z') return ch-'A'; else
    if ('a'<=ch && ch<='z') return ch-'a'; else
    if ('0'<=ch && ch<='9') return ch-'0'; else
    printf("ERROR");
    return 0;
}

signed main(){
    scanf("%lld%lld",&w,&s);
    scanf("%s",a+1); n=strlen(a+1);

    int now_mode = 0; // 0 Upper; 1 Lower; 2 Number
    for (int i=1;i<=n;i++){
        if (now_mode != get_type(a[i])){
            change_mode(now_mode,get_type(a[i]));
            now_mode = get_type(a[i]);
        }
        dat.push_back(get_code(a[i]));
    }
    if (dat.size()&1) dat.push_back(29);
    for (int i=0;i<dat.size();i+=2) d.push_back(dat[i]*30 + dat[i+1]);

    n=d.size();
    if (s!=-1){
        k=1<<(s+1);
        while ((k+n+1)%w) d.push_back(900),n++;
        reverse(d.begin(),d.end());
        d.push_back(++n);

        // 计算 g = (x-3)(x-3^2)...(x-3^k)
        int times3 = -3;
        g[0]=1;
        for (int i=1;i<=k;i++){
            // g = g * (x-times3)
            for (int t=i;t>0;t--) g[t] = (g[t-1] + g[t]*times3%tt)%tt;
            g[0] = g[0]*times3%tt;
            times3 = times3*3%tt;
        }

        for (int i=0;i<d.size();i++) xd[i+k] = d[i]%tt;
        // 多项式取模（参考多项式除法） r = xd % g
        for (int i=k+n-1;i>=k;i--){
            int now_cnt = xd[i] / g[k];
            for (int j=k;j>=0;j--) xd[i-(k-j)] = (xd[i-(k-j)] - now_cnt*g[j]%tt + tt)%tt;
        }
        for (int i=0;i<k;i++) r[i]=(tt-xd[i])%tt;
    } else {
        k=0;
        while ((n+1)%w) d.push_back(900),n++;
        reverse(d.begin(),d.end());
        d.push_back(++n);
    }
    for (int i=n-1;i>=0;i--) printf("%lld\n",d[i]);
    for (int i=k-1;i>=0;i--) printf("%lld\n",r[i]);
    return 0;
}