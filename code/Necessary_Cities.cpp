#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Graph{
    int n;
    vector<vector<int>> nxt;
    vector<int> ap;

    Graph(int _n) : n(_n), nxt(n+1) {}

    void add_edge(int a, int b){
        nxt[a].push_back(b);
    }

    vector<int> find_ap(){
        vector<bool> vis(n+1), instk(n+1);
        vector<int> dfn(n+1), low(n+1);
        int t = 0;

        auto dfs = [&](auto &&dfs, int u, int pa) -> void {
            bool is_ap = 0;
            vis[u] = instk[u] = 1;
            dfn[u] = low[u] = ++t;
            int chd = 0;

            for(int v: nxt[u]){
                if(v == pa) continue;
                
                if(!vis[v]){
                    chd++;
                    dfs(dfs,v,u);
                    low[u] = min(low[u], low[v]);

                    if(low[v] >= dfn[u]) is_ap = 1;
                }
                else if(instk[v]){
                    low[u] = min(low[u], dfn[v]);
                }
            }

            if(pa == 0 && chd < 2) is_ap = 0;

            if(is_ap){
                ap.push_back(u);
            }

        };
        
        dfs(dfs,1,0);
        
        return ap;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    Graph g(n);

    while(m--){
        int a,b;
        cin>>a>>b;
        g.add_edge(a,b);
        g.add_edge(b,a);    
    }

    auto ans = g.find_ap();

    cout << ans.size() << '\n';
    for(auto x: ans) cout << x << ' ';
}