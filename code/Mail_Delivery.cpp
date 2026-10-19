#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
struct Graph{
    int n;
    vector<vector<pair<int,int>>> nxt;
    vector<int> deg;
    int edge_id = 0;
 
    Graph(int _n) : n(_n), nxt(n+1), deg(n+1) {}
 
    void add_edge(int a, int b){
        nxt[a].push_back({++edge_id, b});
        nxt[b].push_back({edge_id, a});
        deg[a]++;
        deg[b]++;
    }
 
    optional<vector<int>> get_ans(int m){
        vector<int> ans;
        vector<bool> vis(m+1);
        vector<int> ptr(n+1);
 
        auto dfs = [&](auto &&dfs, int u) -> void {
            // cerr << u << ' ' ;
            for(; ptr[u] < nxt[u].size(); ptr[u]++){
                auto [id,v] = nxt[u][ptr[u]];
                if(vis[id]) continue;
                vis[id] = 1;
                dfs(dfs, v);
            }
            ans.push_back(u);
        };
 
        int odd_cnt = 0;
        for(int i=1; i<=n; i++){
            if(deg[i] & 1) odd_cnt++;
        }
 
        if(odd_cnt > 0){
            return nullopt;
        }
 
        dfs(dfs, 1);
 
        if(ans.size() != m+1){
            return nullopt;
        }
        
        return ans;
 
    }
 
};
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
 
    Graph g(n);
 
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g.add_edge(a,b);
    }
 
    auto ans = g.get_ans(m);

    if(ans){
        for(int x: *ans) cout << x << ' ';
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
}