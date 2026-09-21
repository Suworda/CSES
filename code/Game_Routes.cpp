#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 100005;
const int M = 1e9+7;

struct Graph{
    int n;
    vector<vector<int>> pre;
    vector<int> dp;
    
    Graph(int n) : n(n), pre(n+1), dp(n+1) {}

    void add_edge(int a, int b){
        pre[b].push_back(a);
    }

    void dfs(int u){
        if(dp[u]) return;

        if(u == 1){
            dp[u] = 1;
            return;
        }

        for(int v: pre[u]){
            dfs(v);
            dp[u] += dp[v];
            dp[u] %= M;
        }
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

    g.dfs(n);

    cout << g.dp[n] << '\n';
}