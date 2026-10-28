#include <bits/stdc++.h>
using namespace std;
#define int unsigned int 
#define ll long long
 
const int M = 1e9+7;
int dp[20][1048576];
bool vis[20][1048576];
 
struct Graph{
    int n;
    vector<vector<int>> pre;
 
    Graph(int _n): n(_n), pre(n+1) {}
 
    void add_edge(int a, int b){
        pre[b].push_back(a);
    }
 
    int get_ans(){
        dp[0][1] = 1;
        vis[0][1] = 1;
 
        auto dfs = [&](auto &&dfs, int u, int s) -> int {
            if(!(s & 1)) return 0;
            if(!((s >> u) & 1)) return 0;
            if(vis[u][s]) return dp[u][s];
 
            ll rst = 0;
            int x = s - (1 << u);
            for(int v: pre[u]){
                rst += dfs(dfs, v, x);
                if(rst >= M) rst -= M;
            }
            vis[u][s] = 1;
            return dp[u][s] = rst;
        };
 
        dfs(dfs,n-1,(1 << n) - 1);
 
        return dp[n-1][(1 << n) - 1];
    }
 
};
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
 
    Graph g(n);
 
    while(m--){
        int a, b;
        cin>>a>>b;
        a--; b--;
        g.add_edge(a, b);
    }
 
    cout << g.get_ans() << '\n';
    
 
}