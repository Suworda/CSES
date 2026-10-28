#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Graph{
    int n, m;
    vector<vector<int>> nxt;
    vector<int> indeg, outdeg;

    Graph(int _n, int _m): n(_n), m(_m), indeg(n+1), outdeg(n+1), nxt(n+1) {}

    void add_edge(int a, int b){
        nxt[a].push_back(b);
        outdeg[a]++;
        indeg[b]++;
    }

    bool may_have_ans(){
        if(outdeg[1] - indeg[1] != 1) return false;
        if(indeg[n] - outdeg[n] != 1) return false;
        
        for(int i=2; i<=n-1; i++){
            if(indeg[i] != outdeg[i]) return false;
        }

        return true;
    }

    optional<vector<int>> get_ans(){
        vector<int> ans;
        vector<int> ptr(n+1);
        
        auto dfs = [&](auto &&dfs, int u) -> void {
            while(ptr[u] < nxt[u].size()){
                int v = nxt[u][ptr[u]++];
                dfs(dfs, v);
            }
            ans.push_back(u);
        };
        
        dfs(dfs, 1);
        if(ans.size() != m+1) return nullopt;

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    Graph g(n,m);

    while(m--){
        int a, b;
        cin>>a>>b;
        g.add_edge(a,b);
    }

    if(!g.may_have_ans()){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    auto ans = g.get_ans();

    if(!ans){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(int x: *ans) cout << x << ' ' ;
    cout << '\n';


}