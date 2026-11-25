#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll INF = 4e18;
const int LOG = 20;
using pii = pair<int,int>;

struct Segt{
    #define l_id (id*2)
    #define r_id (id*2+1)

    struct Node{
        int mi=INF;
    };

    int n;
    vector<Node> seg;

    Segt(int _n, const vector<int> &a): n(_n), seg(4*n+5){
        build(1, n, 1, a);
    }

    void pull(int id){
        seg[id].mi = min(seg[l_id].mi, seg[r_id].mi);
    }

    void build(int l, int r, int id, const vector<int> &a){
        if(l == r){
            seg[id].mi = a[l];
            return;
        }

        int m = (l+r)/2;
        build(l, m, l_id, a);
        build(m+1, r, r_id, a);

        pull(id);
    }

    void set(int l, int r, int p, int x, int id){
        if(l == r){
            seg[id].mi = x;
            return;
        }

        int m = (l+r)/2;
        if(p <= m) set(l, m, p, x, l_id);
        else set(m+1, r, p, x, r_id);
        
        pull(id);
    }

    int query_min(int l, int r, int ql, int qr, int id){
        if(qr < l || r < ql) return INF;

        if(ql <= l && r <= qr){
            return seg[id].mi;
        }

        int m = (l+r)/2;
        int rst1 = query_min(l, m, ql, qr, l_id);
        int rst2 = query_min(m+1, r, ql, qr, r_id);

        return min(rst1, rst2);
    }

    void set(int p, int x){
        set(1, n, p, x, 1);
    }

    int query_min(int l, int r){
        return query_min(1, n, l, r, 1);
    }

    #undef l_id
    #undef r_id
};

struct HLD{
    int n;
    vector<vector<int>> nxt;
    vector<int> pa, dep, sz, heavy;
    vector<int> top, pos;

    Segt segt;

    HLD(int _n): n(_n), nxt(n+1),
        pa(n+1), dep(n+1), sz(n+1),
        heavy(n+1), top(n+1), pos(n+1),
        segt(n, vector<int>(n+1, INF)){}

    void add_edge(int a, int b){
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }

    void build(int root = 1){
        int timer = 0;

        auto dfs1 = [&](auto &&dfs1, int u, int p) -> void {
            pa[u] = p;
            dep[u] = dep[p] + 1;
            
            heavy[u] = 0;
            sz[u] = 1;
            int mx = 0;
            for(int v: nxt[u]){
                if(v == p) continue;

                dfs1(dfs1, v, u);
                
                sz[u] += sz[v];
                if(sz[v] > mx){
                    heavy[u] = v;
                    mx = sz[v];
                }
            }
        };

        auto dfs2 = [&](auto &&dfs2, int u, int t) -> void {
            pos[u] = ++timer;
            top[u] = t;
            
            if(heavy[u]) dfs2(dfs2, heavy[u], t);

            for(int v: nxt[u]){
                if(v == pa[u]) continue;

                if(v != heavy[u]) dfs2(dfs2, v, v);
            }
        };

        dfs1(dfs1, root, 0);

        dfs2(dfs2, root, root);
    }

    void update(int u, int x){
        segt.set(pos[u], x);
    }

    int query(int u, int v){
        int rst = INF;
        while(top[u] != top[v]){
            if(dep[top[u]] > dep[top[v]]){
                rst = min(rst, segt.query_min(pos[top[u]], pos[u]));
                u = pa[top[u]];
            }
            else{
                rst = min(rst, segt.query_min(pos[top[v]], pos[v]));
                v = pa[top[v]];
            }
        }

        if(dep[u] < dep[v]) rst = min(rst, segt.query_min(pos[u], pos[v]));
        else rst = min(rst, segt.query_min(pos[v], pos[u]));

        return rst;
    }
};

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
        for(int i=1; i<=n; i++){
            if(outdeg[i] == 0) q.push(i);
        }

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

    Graph build_sdom(int root = 1){
        vector<int> dfn(n+1), order(n+1);
        vector<int> pa(n+1), sdom(n+1);
        vector<bool> vis(n+1);

        HLD hld(n);
        int timer = 0;

        auto dfs = [&](auto &&dfs, int u, int p) -> void {
            if(vis[u]) return;

            dfn[u] = ++timer;
            order[timer] = u;
            if(p){
                pa[u] = p;
                hld.add_edge(p, u);
            }
            vis[u] = 1;


            for(auto [v, _]: nxt[u]){
                dfs(dfs, v, u);
            }
        };

        auto build_up = [&](vector<array<int, LOG>> &up) -> void {
            for(int i=1; i<=n; i++){
                up[i][0] = pa[i];
            }

            for(int j=1; j<LOG; j++){
                for(int i=1; i<=n; i++){
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        };
        // 建立 DFS Tree
        dfs(dfs, root, 0);

        hld.build(root);

        vector<array<int, LOG>> up(n+1);
        build_up(up);

        // 計算半支配者
        for(int i=timer; i>=2; i--){
            int v = order[i];
            int best = INF;

            for(auto [x, _]: pre[v]){
                // 不可達的點、自環：略過
                if(!dfn[x] || x == v) continue;

                // dfn[x] < i：直接更新
                if(dfn[x] < i) best = min(best, dfn[x]);
                
                // dfn[x] > i：HLD 查詢
                if(dfn[x] > i){
                    int p = x;

                    for(int j=LOG-1; j>=0; j--){
                        if(dfn[up[p][j]] > dfn[v]){
                            p = up[p][j];
                        }
                    }

                    int rst = hld.query(p, x);
                    best = min(best, rst);
                }
            }

            sdom[v] = order[best];
            hld.update(v, best);
        }

        // 建立等價 DAG 並回傳
        Graph dag(n);
        for(int i=2; i<=timer; i++){
            int v = order[i];
            dag.add_edge(pa[v], v, 0);
            dag.add_edge(sdom[v], v, 0);
        }

        return dag;
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

    Graph g2 = g.to_DAG();
    Graph sdom_dag = g2.build_sdom();

    Tree tree(n);
    tree.build_dom(sdom_dag);

    auto ans = tree.get_ans();

    cout << ans.size() << '\n';
    for(int x: ans) cout << x << ' ' ;
    cout << '\n';
}