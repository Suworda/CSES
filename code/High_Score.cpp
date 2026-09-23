#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int INF = 9e18;
// using pii = pair<int,int>;

struct Graph{
    int n;
    vector<vector<int>> nxt;
    vector<tuple<int,int,int>> edge;
    vector<int> dp;

    Graph(int _n): n(_n), dp(n+1), nxt(n+1) {
        for(int i=1; i<=n; i++){
            dp[i] = -INF;
        }
        dp[1] = 0;
    }

    void add_edge(int a, int b, int c){
        nxt[a].push_back(b);
        edge.push_back({a,b,c});
    }

    bool can_vis(int a, int b){
        vector<bool> vis(n+1);
        auto dfs = [&](auto &&dfs, int u) -> bool {
            if(vis[u]) return false;
            vis[u] = 1;
            if(u == b) return true;

            for(int v: nxt[u]){
                if(dfs(dfs,v)) return true;
            }

            return false;
        };

        return dfs(dfs,a);
    }

    int find_ans(){
        for(int i=0; i<n; i++){
            for(auto [u,v,w]: edge){
                dp[v] = max(dp[v], dp[u]+w);
            }
        }

        bool is_inf = 0;

        for(auto [u,v,w]: edge){
            if(dp[u] + w > dp[v] && can_vis(1,u) && can_vis(v,n)) is_inf = 1;
        }

        if(is_inf) return -1;
        else return dp[n];
    }

};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    Graph g(n);

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g.add_edge(a,b,c);
    }

    int ans = g.find_ans();

    cout << ans << '\n';

}