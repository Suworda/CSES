#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Graph{
    int n;
    int scc_size = 0;
    vector<vector<int>> nxt, pre;
    vector<int> val, new_val;
    vector<int> scc;

    Graph(int _n): n(_n), scc(n+1), nxt(n+1), pre(n+1), val(n+1), new_val(n+1) {}

    void add_edge(int a, int b){
        nxt[a].push_back(b);
        pre[b].push_back(a);
    }

    void find_scc(){
        vector<bool> vis(n+1), instk(n+1);
        vector<int> dfn(n+1), low(n+1), stk;
        int timer = 0;
        int cur_id = 0;

        auto dfs = [&](auto &&dfs, int u) -> void {
            dfn[u] = low[u] = ++timer;
            stk.push_back(u);
            vis[u] = instk[u] = 1;

            for(int v: nxt[u]){
                if(!vis[v]){
                    dfs(dfs, v);
                    low[u] = min(low[u], low[v]);
                }
                else if(instk[v]){
                    low[u] = min(low[u], dfn[v]);
                }
            }

            if(low[u] == dfn[u]){
                int x;
                cur_id++;
                scc_size++;

                vector<int> v;
                int cur_val = 0;

                do{
                    x = stk.back(), stk.pop_back();
                    v.push_back(x);
                    cur_val += val[x];
                }while(x != u);

                for(int x: v){
                    scc[x] = cur_id;
                    instk[x] = 0;
                }
                new_val[cur_id] = cur_val;
            }
        };

        for(int i=1; i<=n; i++){
            if(!vis[i]) dfs(dfs, i);
        }
    } 

    int get_ans(){
        vector<bool> vis(n+1);
        vector<int> dp(n+1);
        auto dfs = [&](auto &&dfs, int u) -> int {
            if(vis[u]) return dp[u];
            vis[u] = 1;
            
            ll rst = 0;
            for(int v: pre[u]){
                dfs(dfs, v);
                rst = max(rst, dp[v]);
            }
            
            return dp[u] = rst + val[u];
        };

        int ans = 0;
        for(int i=1; i<=n; i++) if(!vis[i]) ans = max(ans, dfs(dfs, i));
        return ans;
    }

};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    Graph g(n);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        g.val[i] = x;
    }

    while(m--){
        int a, b;
        cin>>a>>b;
        g.add_edge(a, b);
    }

    g.find_scc();

    Graph g2(g.scc_size);

    for(int i=1; i<=g.scc_size; i++){
        g2.val[i] = g.new_val[i];
    }

    for(int u=1; u<=n; u++){
        for(int v: g.nxt[u]){
            if(g.scc[v] != g.scc[u]){
                g2.add_edge(g.scc[u], g.scc[v]);
            }
        }
    }

    cout << g2.get_ans() << '\n';



}