#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

const int maxn=1e3+5;

int n;
int a[maxn];

double avg=0.0, D=0.0;

#define sqr(_) ((_)*(_))

signed main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i], avg+=a[i];
    avg /= n;
    for (int i=1;i<=n;i++) D+=sqr(avg-a[i]);
    D /= n;

    for (int i=1;i<=n;i++) cout<<(a[i]-avg)/sqrt(D)<<endl;
    return 0;
}