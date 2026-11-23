#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int INF = (1LL << 60);
using pii = pair<int,int>;

struct Graph{
    int n;
    vector<vector<pii>> nxt, pre;
    vector<int> dis;
    vector<int> ori_outdeg;

    Graph(int _n): n(_n), nxt(n+1), pre(n+1), dis(n+1, INF), ori_outdeg(n+1){}

    void add_edge(int a, int b, int c){
        nxt[a].push_back({b, c});
        pre[b].push_back({a, c});
        ori_outdeg[a]++;
    }

    void dijkstra(){
        priority_queue<pii, vector<pii>, greater<>> pq;
        vector<bool> vis(n+1);

        pq.push({0, 1});
        
        while(pq.size()){
            auto [cur, u] = pq.top(); pq.pop();

            if(vis[u]) continue;

            vis[u] = 1;
            dis[u] = cur;

            for(auto [v, w]: nxt[u]){
                pq.push({cur+w, v});
            }
        }
    }

    Graph to_DAG(){
        Graph g2(n);

        queue<int> q;
        vector<bool> vis(n+1);

        q.push(n);
        vis[n] = 1;
        while(q.size()){
            int v = q.front(); q.pop();

            for(auto [u, w]: pre[v]){
                if(dis[u] + w == dis[v]){
                    g2.add_edge(u, v, w);
                    
                    if(!vis[u]){
                        vis[u] = 1;
                        q.push(u);
                    }
                }
            }
        }
        
        return g2;
    }

    vector<int> topo_sort(){
        auto outdeg = ori_outdeg;
        vector<int> order;

        queue<int> q;
        q.push(n);

        while(q.size()){
            int u = q.front(); q.pop();

            order.push_back(u);

            for(auto [v, w]: pre[u]){
                outdeg[v]--;
                if(outdeg[v] == 0){
                    q.push(v);
                }
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }

    vector<int> get_ans(){
        vector<int> ans;
        vector<int> pos(n+1);
        vector<int> order = topo_sort();
        vector<bool> need(n+1);

        for(int i=0; i<order.size(); i++){
            pos[order[i]] = i;
        }

        int r = 0;
        for(int u: order){
            if(r <= pos[u]) need[u] = 1;
            r = max(r, pos[u]);
            for(auto [v, w]: nxt[u]){
                r = max(r, pos[v]);
            }
        }

        for(int i=1; i<=n; i++) if(need[i]) ans.push_back(i);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    Graph g(n);

    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }

    g.dijkstra();

    Graph g2 = g.to_DAG();

    vector<int> ans = g2.get_ans();

    cout << ans.size() << '\n';
    for(int x: ans) cout << x << ' ' ;


}