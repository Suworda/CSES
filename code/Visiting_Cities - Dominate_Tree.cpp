#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int LOG = 20;
const int INF = 4e18;
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
};


struct Tree{
    int n;
    vector<int> dep;
    vector<array<int, LOG>> up;

    Tree(int _n): n(_n), dep(n+1), up(n+1){
        up[1].fill(1);
    }

    void build_dom(Graph &g){
        auto order = g.topo_sort();

        for(int v: order){
            if(v == 1) continue;

            int lca = 0;
            for(auto [u, _]: g.pre[v]){
                if(!lca) lca = u;
                else lca = LCA(lca, u);
            }

            if(lca) add(v, lca);
        }
    }
    
    void add(int v, int p){
        dep[v] = dep[p] + 1;
        up[v][0] = p;

        for(int j=1; j<LOG; j++){
            up[v][j] = up[up[v][j-1]][j-1];
        }
    }

    int LCA(int a, int b){
        if(dep[a] > dep[b]){
            for(int i=LOG-1; i>=0; i--){
                if(dep[a] > dep[b]){
                    if(dep[up[a][i]] >= dep[b]) a = up[a][i];
                }
            }
        }
        else if(dep[b] > dep[a]){
            for(int i=LOG-1; i>=0; i--){
                if(dep[b] > dep[a]){
                    if(dep[up[b][i]] >= dep[a]) b = up[b][i];
                }
            }
        }
        
        if(a == b) return a;

        for(int i=LOG-1; i>=0; i--){
            if(up[a][i] != up[b][i]){
                a = up[a][i];
                b = up[b][i];
            }
        }

        return up[a][0];
    }

    vector<int> get_ans(){
        vector<int> ans;
        int x = n;
        while(x != 1){
            ans.push_back(x);
            x = up[x][0];
        }
        ans.push_back(1);

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

    Tree tree(n);

    Graph dag = g.to_DAG();
    tree.build_dom(dag);

    auto ans = tree.get_ans();

    cout << ans.size() << '\n';
    
    for(int x: ans) cout << x << ' ';
    cout << '\n';
}