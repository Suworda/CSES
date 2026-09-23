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

    vector<int> find_ans(int k){
        vector<int> vis(n+1);
        priority_queue<pii, vector<pii>, greater<>> pq;
        
        vector<int> rst;

        pq.push({0,1});

        while(pq.size()){
            auto [d,u] = pq.top(); pq.pop();

            if(vis[u] > k) continue;
            vis[u]++;
            dis[u] = d;
            if(u == n) rst.push_back(dis[u]); 

            for(auto [v,w]: nxt[u]){
                pq.push({d+w, v});
            }
        }

        return rst;
    }
};


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,k;
    cin>>n>>m>>k;

    Graph g(n);

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g.add_edge(a,b,c);
    }

    auto ans = g.find_ans(k);

    for(int i=0; i<k; i++) cout << ans[i] << ' ';
}