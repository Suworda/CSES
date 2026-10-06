#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Graph{
    int n;
    vector<vector<int>> nxt, pre, cycles;
    vector<int> ans;

    Graph(int _n): n(_n), nxt(n+1), pre(n+1), ans(n+1) {}

    void add_edge(int a, int b){
        nxt[a].push_back(b);
        pre[b].push_back(a);
    }

    void find_cycles(){
        vector<bool> vis(n+1), instk(n+1);
        vector<int> stk(n+1);

        auto dfs = [&](auto &&dfs, int u) -> void {
            if(vis[u]) return;
            stk.push_back(u);
            vis[u] = instk[u] = 1;

            for(int v: nxt[u]){
                if(!vis[v]){
                    dfs(dfs, v);
                }
                else if(instk[v]){
                    int x;
                    vector<int> cur;
                    do{
                        x = stk.back(); stk.pop_back();
                        instk[x] = 0;
                        cur.push_back(x);
                    }while(x != v);
                    cycles.push_back(cur);
                }
            }
        };

        for(int i=1; i<=n; i++){
            if(!vis[i]){
                while(stk.size()){
                    instk[stk.back()] = 0;
                    stk.pop_back();
                }
                dfs(dfs, i);
            }
        }
    }

    void get_ans(){
        find_cycles();
        vector<bool> vis(n+1);

        for(int i=0; i<cycles.size(); i++){
            queue<int> q;
            int len = cycles[i].size();
            for(int x: cycles[i]){
                ans[x] = len;
                q.push(x);
                vis[x] = 1;
            }

            while(q.size()){
                int u = q.front(); q.pop();

                for(int v: pre[u]){
                    if(!vis[v]){
                        vis[v] = 1;
                        ans[v] = ans[u]+1;
                        q.push(v);
                    }
                }
            }
        }
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;

    Graph g(n);
    for(int i=1; i<=n; i++){
        int t;
        cin>>t;
        g.add_edge(i,t);
    }

    g.get_ans();
    auto ans = g.ans;
    for(int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';
}