#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Graph{
    int d;
    int n;
    vector<vector<int>> nxt;
    vector<int> scc;

    Graph(int _n): n(_n), nxt(n+1), d(_n/2), scc(n+1) {}

    void add_edge(char a, int x, char b, int y){
        if(a == '+' && b == '+'){
            nxt[x+d].push_back(y);
            nxt[y+d].push_back(x);
        }
        if(a == '+' && b == '-'){
            nxt[x+d].push_back(y+d);
            nxt[y].push_back(x);
        }
        if(a == '-' && b == '+'){
            nxt[x].push_back(y);
            nxt[y+d].push_back(x+d);
        }
        if(a == '-' && b == '-'){
            nxt[x].push_back(y+d);
            nxt[y].push_back(x+d);
        }
    }

    void find_scc(){
        vector<bool> vis(n+1), instk(n+1);
        vector<int> stk, dfn(n+1), low(n+1);
        int cur_id = 0;
        int timer = 0;

        auto dfs = [&](auto &&dfs, int u) -> void {
            dfn[u] = low[u] = ++timer;
            vis[u] = instk[u] = 1;
            stk.push_back(u);

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
                cur_id++;
                int x;
                do{
                    x = stk.back(); stk.pop_back();
                    scc[x] = cur_id;
                    instk[x] = 0;
                }while(x != u);
            }
        };

        for(int i=1; i<=n; i++){
            if(!vis[i]) dfs(dfs, i);
        }
    }

    bool have_ans(){
        for(int i=1; i<=d; i++){
            if(scc[i] == scc[i+d]) return false;
        }
        return true;
    }

    string get_ans(){
        string ans;
        for(int i=1; i<=d; i++){
            if(scc[i+d] > scc[i]) ans.push_back('+');
            else ans.push_back('-');
        }
        return ans;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin>>m>>n;
    
    Graph g(n*2);
    while(m--){
        char a, b;
        int x, y;
        cin>>a>>x>>b>>y;
        g.add_edge(a,x,b,y);
    }

    g.find_scc();
    if(!g.have_ans()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    auto ans = g.get_ans();
    for(char c: ans) cout << c << ' ';
}