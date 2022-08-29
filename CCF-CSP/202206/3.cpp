// 80pts，好像优化不过呢……

#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

const int maxn=565;
const int W = 63; // bitset 的字宽度，int 30 不够，还是超时 QwQ

class mybitset { // bitset 会和 STL 里的冲突 =_=
    private:
        unsigned long long a[maxn/W];

    public:
        mybitset(){
            memset(a,0,sizeof(a));
        }

        void set(int x){
            a[x/W] |= 1ll<<(x%W);
        }

        bool get(int x){
            return a[x/W] & (1ll<<(x%W));
        }

        void merge(mybitset& bb){
            for (int i=0;i<maxn/W;i++) a[i]|=bb.a[i];
        }
};

struct role {
    int id;
    string name;
    map<string, bool> opt,res_kind,res_name;

    role(){
        name = "";
        opt.clear(); res_kind.clear(); res_name.clear();
    }
};


struct user_group {
    string name;
    mybitset roles;

    user_group(){
        name = "";
    }
};

struct user {
    string name;
    mybitset roles;

    user(){
        name = "";
    }
};

int n,m,q;

role* id2role[maxn];
map<string, role*> name2role;
map<string, user*> name2user;
map<string, user_group*> name2group;

void create_link(string& type, string& u_name, role* now_role){
    if (type == "u"){
        if (!name2user[u_name]){
            user* now_user = new user;
            now_user->name = u_name;
            now_user->roles.set(now_role->id);
            name2user[u_name] = now_user;
        } else {
            user* now_user = name2user[u_name];
            now_user->roles.set(now_role->id);
        }
    } else {
        if (!name2group[u_name]){
            user_group* now_group = new user_group;
            now_group->name = u_name;
            now_group->roles.set(now_role->id);
            name2group[u_name] = now_group;
        } else {
            user_group* now_group = name2group[u_name];
            now_group->roles.set(now_role->id);
        }
    }
}

bool check_perm(role* now_role, string& opt, string& res_kind, string& res_name){
    if (!now_role->opt["*"] && !now_role->opt[opt]) return false;
    if (!now_role->res_kind["*"] && !now_role->res_kind[res_kind]) return false;
    if (now_role->res_name.size() != 0 && !now_role->res_name[res_name]) return false;
    return true;
}

signed main(){
    cin >> n >> m >> q;
    for (int i=0;i<n;i++){
        role* now_role = new role;
        now_role->id = i;
        cin >> now_role->name;
        id2role[now_role->id] = now_role;
        name2role[now_role->name] = now_role;

        int x; cin>>x;
        while (x--){
            string s; cin>>s;
            now_role->opt[s]=true;
        }
        cin>>x;
        while (x--){
            string s; cin>>s;
            now_role->res_kind[s]=true;
        }
        cin>>x;
        while (x--){
            string s; cin>>s;
            now_role->res_name[s]=true;
        }
    }
    for (int i=0;i<m;i++){
        string role_name; cin>>role_name;
        role* now_role = name2role[role_name];
        int x; cin>>x;
        while (x--){
            string type, u_name;
            cin>>type>>u_name;
            create_link(type, u_name, now_role);
        }
    }

    while (q--){
        string u_name; cin>>u_name;
        user* now_user = name2user[u_name];
        if (!now_user){
            now_user = new user;
            now_user->name = u_name;
            name2user[u_name] = now_user;
        }
        mybitset roles;
        roles.merge(now_user->roles);
        int x; cin>>x;
        while (x--){
            string g_name; cin>>g_name;
            user_group* now_group = name2group[g_name];
            if (now_group) roles.merge(now_group->roles);
        }

        string opt, res_kind, res_name;
        cin>>opt>>res_kind>>res_name;
        bool ans=false;
        for (int i=0;i<n;i++) if (roles.get(i)){
            if (check_perm(id2role[i], opt, res_kind, res_name)){
                ans=true; break;
            }
        }
        cout<<(ans?1:0)<<endl;
    }
    return 0;
}