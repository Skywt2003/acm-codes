#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<map>

// using namespace std;
// #define int long long

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

const int maxn=55;

const int dir[4][2]={{-1,0}, {0,1}, {1,0}, {0,-1}};

int t;
int n,m;

std::map<std::pair<int,int>, bool> vis;

bool can_go(int x,int y){
	if (x<1 || x>n || y<1 || y>m) return false;
	return !vis[std::make_pair(x,y)];
}

signed main(){
	t=read();
	while (t--){
		vis.clear();
		std::vector<int> ans; ans.clear();

		n=read(),m=read();
		std::vector<std::pair<int,int> > vec[2];
		int i=0;
		for (int x=(n+1)/2; x<=n/2+1; x++)
			for (int y=(m+1)/2; y<=m/2+1; y++)
				vec[i].push_back(std::make_pair(x,y)),
				vis[std::make_pair(x,y)] = true;
		for (;;){
			if (vec[i].size() == 0) break;
			ans.push_back((int)vec[i].size());
			vec[1-i].clear();
			for (int j=0;j<(int)vec[i].size();j++)
				for (int k=0;k<4;k++){
					int xx = vec[i][j].first + dir[k][0];
					int yy = vec[i][j].second + dir[k][1];
					if (can_go(xx,yy))
						vec[1-i].push_back(std::make_pair(xx,yy)),
						vis[std::make_pair(xx,yy)] = true;
				}
			i=1-i;
		}
		int now_ans = (n - (n+1)/2) + (m - (m+1)/2);
		for (int i=0; i<(int)ans.size(); i++){
			for (int j=0; j<ans[i]; j++) printf("%d ",now_ans);
			now_ans++;
		}
		printf("\n");
	}
	return 0;
}