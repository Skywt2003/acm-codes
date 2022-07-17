#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int t;
int a,b;

signed main(){
    t=read();
    while (t--){
        a=read(),b=read();
        if (a==1 && b==0){
            putchar('0'); putchar('\n');
        } else if (a==0 && b==1){
            putchar('1'); putchar('\n');
        } else {
            for (int i=1;i<=min(a,b);i++) putchar('0'),putchar('1');
            int pre=min(a,b); a-=pre,b-=pre;
            for (int i=1;i<=a;i++) putchar('0');
            for (int i=1;i<=b;i++) putchar('1');
            putchar('\n');
        }
    }
    return 0;
}