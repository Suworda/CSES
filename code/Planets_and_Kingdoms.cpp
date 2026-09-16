#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long

struct Graph{
    int n;
    int scc_cnt = 0;
    vector<vector<int>> nxt;
    vector<int> scc;

    Graph(int n): n(n), nxt(n+1), scc(n+1) {}

    void add_edge(int u, int v){
        nxt[u].push_back(v);
    }

    vector<int> find_scc(){
        int timer = 0, ans_id = 0;
        vector<int> dfn(n+1), low(n+1), stk;
        vector<bool> instk(n+1), vis(n+1);

        auto dfs = [&](auto &&dfs, int u) -> void {
            if(vis[u]) return;
            
            dfn[u] = low[u] = ++timer;
            vis[u] = 1;
            stk.push_back(u);
            instk[u] = 1;
            
            for(int v: nxt[u]){
                if(!vis[v]){
                    dfs(dfs, v);
                    low[u] = min(low[u], low[v]);
                }
                else if(instk[v]){
                    low[u] = min(low[u], dfn[v]);
                }
            }
            
            if(dfn[u] == low[u]){
                ans_id++;
                int x;
                do{
                    x = stk.back(); stk.pop_back();
                    scc[x] = ans_id;
                    instk[x] = 0;
                }while(x != u);
            }

        };

        for(int i=1; i<=n; i++){
            if(!vis[i]) dfs(dfs,i);
        }

        scc_cnt = ans_id;
        return scc;
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
    }

    vector<int> scc = g.find_scc();

    cout << g.scc_cnt << '\n';
    for(int i=1; i<=n; i++){
        cout << scc[i] << ' ';
    }
    cout << '\n';
}