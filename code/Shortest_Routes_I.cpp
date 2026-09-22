#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
using pii = pair<int,int>;

struct Graph{
    int n;
    vector<vector<pii>> nxt;
    vector<int> dis;

    Graph(int _n) : n(_n), nxt(n+1), dis(n+1) {}

    void add_edge(int a, int b, int c){
        nxt[a].push_back({b,c});
    }

    vector<int> get_dis(){
        vector<bool> vis(n+1);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,1});

        while(pq.size()){
            auto [cur,u] = pq.top(); pq.pop();

            if(vis[u]) continue;
            vis[u] = 1;
            dis[u] = cur;

            for(auto [v,w]: nxt[u]){
                pq.push({cur+w, v});
            }
        }

        return dis;

    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    Graph g(n);

    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        g.add_edge(a,b,c);
    }

    auto dis = g.get_dis();

    for(int i=1; i<=n; i++) cout << dis[i] << ' ';


}