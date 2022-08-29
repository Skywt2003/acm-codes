// 朴素的算法能拿到 70pts
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct role {
    string name;
    vector<string> opt, res_kind, res_name;

    role(){
        name = "";
        opt.clear(); res_kind.clear(); res_name.clear();
    }
};


struct user_group {
    string name;
    vector<role*> roles;

    user_group(){
        name = "";
        roles.clear();
    }
};

struct user {
    string name;
    vector<role*> roles;

    user(){
        name = "";
        roles.clear();
    }
};

int n,m,q;

map<string, role*> name2role;
map<string, user*> name2user;
map<string, user_group*> name2group;

void create_link(string& type, string& u_name, role* now_role){
    if (type == "u"){
        if (!name2user[u_name]){
            user* now_user = new user;
            now_user->name = u_name;
            now_user->roles.push_back(now_role);
            name2user[u_name] = now_user;
        } else {
            user* now_user = name2user[u_name];
            now_user->roles.push_back(now_role);
        }
    } else {
        if (!name2group[u_name]){
            user_group* now_group = new user_group;
            now_group->name = u_name;
            now_group->roles.push_back(now_role);
            name2group[u_name] = now_group;
        } else {
            user_group* now_group = name2group[u_name];
            now_group->roles.push_back(now_role);
        }
    }
}

bool check_perm(role* now_role, string opt, string res_kind, string res_name){
    bool flg=false;
    for (int i=0;i<now_role->opt.size();i++)
        if (now_role->opt[i] == opt || now_role->opt[i] == "*"){
            flg=true; break;
        }
    if (!flg) return false;
    flg=false;
    for (int i=0;i<now_role->res_kind.size();i++)
        if (now_role->res_kind[i] == res_kind || now_role->res_kind[i] == "*"){
            flg=true; break;
        }
    if (!flg) return false;
    flg = (now_role->res_name.size() == 0);
    for (int i=0;i<now_role->res_name.size() && !flg;i++)
        if (now_role->res_name[i] == res_name){
            flg=true; break;
        }
    if (!flg) return false;
    return true;
}

signed main(){
    cin >> n >> m >> q;
    for (int i=1;i<=n;i++){
        role* now_role = new role;
        cin >> now_role->name;
        name2role[now_role->name] = now_role;

        int x; cin>>x;
        while (x--){
            string s; cin>>s;
            now_role->opt.push_back(s);
        }
        cin>>x;
        while (x--){
            string s; cin>>s;
            now_role->res_kind.push_back(s);
        }
        cin>>x;
        while (x--){
            string s; cin>>s;
            now_role->res_name.push_back(s);
        }
    }
    for (int i=1;i<=m;i++){
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
        vector<user_group*> groups; groups.clear();
        int x; cin>>x;
        while (x--){
            string g_name; cin>>g_name;
            if (name2group[g_name]) groups.push_back(name2group[g_name]);
        }

        string opt, res_kind, res_name;
        cin>>opt>>res_kind>>res_name;
        bool ans=false;
        for (int i=0;i<now_user->roles.size();i++)
            if (check_perm(now_user->roles[i], opt, res_kind, res_name)){
                ans=true; break;
            }
        for (int i=0;i<groups.size() && !ans;i++)
            for (int j=0;j<groups[i]->roles.size();j++)
                if (check_perm(groups[i]->roles[j], opt, res_kind, res_name)){
                    ans=true;
                    break;
                }
        cout<<(ans?1:0)<<endl;
    }
    return 0;
}