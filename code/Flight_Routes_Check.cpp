#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Graph{
    int n;
    vector<vector<int>> nxt, pre;

    Graph(int _n) : n(_n), nxt(n+1), pre(n+1) {}

    void add_edge(int a, int b){
        nxt[a].push_back(b);
        pre[b].push_back(a);
    }

    tuple<bool,int,int> get_ans(){
        vector<bool> vis(n+1);

        auto dfs1 = [&](auto &&dfs, int u) -> void {
            if(vis[u]) return;
            vis[u] = 1;

            for(int v: nxt[u]){
                dfs(dfs, v);
            }
        };

        auto dfs2 = [&](auto &&dfs, int u) -> void {
            if(vis[u]) return;
            vis[u] = 1;

            for(int v: pre[u]){
                dfs(dfs, v);
            }
        };

        dfs1(dfs1, 1);
        bool valid = 1;
        int x = -1, y = -1;
        for(int i=1; i<=n; i++) if(!vis[i]){
            valid = 0;
            x = 1;
            y = i;
        }

        for(int i=1; i<=n; i++) vis[i] = 0;

        dfs2(dfs2, 1);
        for(int i=1; i<=n; i++) if(!vis[i]){
            valid = 0;
            x = i;
            y = 1;
        }
        
        return {valid, x, y};


    }

};

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    Graph g(n);
    while(m--){
        int a, b;
        cin>>a>>b;
        g.add_edge(a, b);
    }

    auto [a, b, c] = g.get_ans();
    if(!a){
        cout << "NO\n";
        cout << b << ' ' << c << '\n';
    }
    else cout << "YES\n";

    

}