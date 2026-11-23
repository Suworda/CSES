#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Graph{
    int n;
    vector<vector<int>> nxt;
    vector<int> indeg;

    Graph(int _n): n(_n), indeg(n+1), nxt(n+1) {}

    void add_edge(int a, int b){
        nxt[a].push_back(b);
        indeg[b]++;
    }

    optional<vector<int>> topo_sort(){
        auto deg = indeg;
        vector<int> rst;

        queue<int> q;
        for(int i=1; i<=n; i++){
            if(deg[i] == 0){
                q.push(i);
            }
        }

        while(q.size()){
            int u = q.front(); q.pop();
            rst.push_back(u);
            for(int v: nxt[u]){
                deg[v]--;
                if(deg[v] == 0){
                    q.push(v);
                }
            }
        }
        if(rst.size() == n) return rst;
        else return nullopt;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin>>n>>m;
    
    Graph g(n);

    while(m--){
        int a, b;
        cin>>a>>b;
        g.add_edge(a, b);
    }

    auto ans = g.topo_sort();

    if(ans){
        for(int x: *ans) cout << x << ' ';
        cout << '\n';

    }
    else{
        cout << "IMPOSSIBLE\n";
    }

    // cout << "return 0";
}