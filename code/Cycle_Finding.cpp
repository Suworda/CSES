#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll INF = 4e18;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;

struct Graph{
    int n;
    vector<tiii> edge;
    vector<int> dis;
    vector<int> from;

    Graph(int _n): n(_n), dis(n+1), from(n+1){
        for(int i=1; i<=n; i++) dis[i] = INF;
        dis[1] = 0;
    }

    void add_edge(int a, int b, int c){
        edge.push_back({a,b,c});
    }

    optional<vector<int>> find_negative_cyle(){
        for(int i=0; i<n; i++){
            for(auto [u,v,w]: edge){
                // cerr << u << ' ' << v << ' ' << w << '\n';
                if(dis[u]+w < dis[v]){
                    dis[v] = dis[u]+w;
                }
            }
        }

        int p = 0;
        for(int i=0; i<n; i++){
            for(auto [u,v,w]: edge){
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    from[v] = u;
                    p = u;
                }
            }
        }

        if(!p) return nullopt;

        set<int> st;
        vector<int> rst;
        int x = p;
        while(!st.count(x)){
            st.insert(x);
            x = from[x];
        }

        p = x;

        do{
            rst.push_back(x);
            x = from[x];
        }while(x != p);
        rst.push_back(x);

        reverse(rst.begin(), rst.end());
        return rst;
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

    auto ans = g.find_negative_cyle();

    if(ans){
        cout << "YES\n";
        for(int x: (*ans)) cout << x << ' ';
    }
    else cout << "NO\n";

    // cout << "return 0";

}