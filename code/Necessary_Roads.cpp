#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Graph{
    int n;
    vector<vector<int>> nxt;
    vector<pair<int,int>> bri;

    Graph(int _n) : n(_n), nxt(n+1) {} 

    void add_edge(int a, int b){
        nxt[a].push_back(b);
    }

    void find_bri(){
        vector<bool> vis(n+1), instk(n+1);
        vector<int> dfn(n+1), low(n+1);
        int t = 0;

        auto dfs = [&](auto &&dfs, int u, int pa) -> void {
            dfn[u] = low[u] = ++t;
            vis[u] = instk[u] = 1;

            for(int v: nxt[u]){
                if(v == pa) continue;
                if(!vis[v]){
                    dfs(dfs,v,u);
                    low[u] = min(low[u], low[v]);
                }
                else if(instk[v]){
                    low[u] = min(low[u], dfn[v]);
                }
            }

            if(low[u] == dfn[u]){
                if(pa) bri.push_back({u,pa});
            }
        };

        dfs(dfs,1,0);

        // for(int i=1; i<=n; i++) cout << i << ' ' << dfn[i] << ' ' << low[i] << '\n';

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

    g.find_bri();

    auto ans = g.bri;

    cout << ans.size() << '\n';
    for(auto [a,b]: ans){
        cout << a << ' ' << b << '\n';
    }
    
} 