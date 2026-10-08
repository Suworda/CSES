#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Graph{
    int n;
    vector<int> nxt;
    vector<vector<int>> pre;
    vector<array<int,35>> jp;
    vector<int> dep, roots, cycle_len;

    Graph(int _n) : n(_n), nxt(n+1), pre(n+1), jp(n+1), dep(n+1), cycle_len(n+1) {}

    void add_edge(int a, int b){
        nxt[a] = b;
        pre[b].push_back(a);
        jp[a][0] = b;
    }

    void set_type(){
        vector<bool> vis(n+1), instk(n+1);
        vector<int> stk;

        auto dfs = [&](auto &&dfs, int u) -> void {
            if(vis[u]) return;
            vis[u] = instk[u] = 1;
            stk.push_back(u);
            
            int v = nxt[u];
            
            if(!vis[v]){
                dfs(dfs,v);
            }
            else if(instk[v]){
                vector<int> vec;
                roots.push_back(u);
                int x;
                do{
                    x = stk.back(); stk.pop_back();
                    vec.push_back(x);
                }while(x != v);

                for(int x: vec){
                    instk[x] = 0;
                    cycle_len[x] = vec.size();
                }
            }
        };

        for(int i=1; i<=n; i++){
            if(!vis[i]){
                for(int x: stk) instk[x] = 0;
                stk.clear();
                dfs(dfs, i);
            }
        }
    }

    void set_dep(){
        vector<bool> vis(n+1);
        auto dfs = [&](auto &&dfs, int u, int cur_dep, int rt) -> void {
            if(vis[u]) return;
            vis[u] = 1;
            dep[u] = cur_dep;
            cycle_len[u] = cycle_len[rt];

            for(int v: pre[u]){
                if(!vis[v]){
                    dfs(dfs, v, cur_dep+1, rt);
                }
            }
        };

        for(int rt: roots) dfs(dfs, rt, 0, rt);
    }

    void init_jp(){
        for(int j=1; j<31; j++){
            for(int i=1; i<=n; i++){
                jp[i][j] = jp[jp[i][j-1]][j-1];
            }
        }
    }

    int query(int a, int b){
        auto can_vis = [&](int a, int b, int dis) -> bool {
            int x = a;
            for(int i=0; i<31; i++){
                if((dis >> i) & 1) x = jp[x][i];
            }
            return x == b;
        };

        int x = dep[a] - dep[b];
        if(x >= 0 && can_vis(a, b, x)) return x;

        else if(can_vis(a, b, x+cycle_len[a])) return x + cycle_len[a];

        else return -1;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin>>n>>q;
    
    Graph g(n);
    for(int i=1; i<=n; i++){
        int t;
        cin>>t;
        g.add_edge(i,t);
    }

    g.set_type();

    g.set_dep();

    g.init_jp();

    while(q--){
        int a, b;
        cin>>a>>b;
        cout << g.query(a, b) << '\n';
    }
}