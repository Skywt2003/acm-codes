#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=2e5+5;

int t,n;
int a[maxn];
int pos[maxn],nxt[maxn],lst[maxn];

std::set<int> s,ns;

signed main(){
	t=read();
	while (t--){
		n=read();
		for (int i=1;i<=n;i++){
			a[i]=read();
			if (pos[a[i]]) lst[i]=pos[a[i]],nxt[pos[a[i]]]=i;
			pos[a[i]]=i;
		}
		for (int i=1;i<=n;i++) if (!lst[i]) pos[a[i]]=i,s.insert(a[i]);
		for (int i=0;i<=n;i++) if (!pos[i]) ns.insert(i);
		

		std::vector<int> vec; vec.clear();
		int head=1;
		while (head<=n){
			int now_ans = *(ns.begin());
			vec.push_back(now_ans);
			int now_num=*(s.lower_bound(now_ans));
			int now_pos=pos[now_num];
			for (int i=head;i<=now_pos;i++){
				if (nxt[i] > now_pos) lst[nxt[i]]=0,s.insert(a);
				if (nxt[i]==0) pos[a[i]]=0,ns.insert(i);
			}
			head = now_pos+1;
		}


		s.clear();
		memset(pos,0,(n+1)*sizeof(int));
		memset(nxt,0,(n+1)*sizeof(int));
		memset(lst,0,(n+1)*sizeof(int));
	}
	return 0;
}