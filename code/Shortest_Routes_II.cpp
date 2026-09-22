#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
using pii = pair<int,int>;

struct Graph{
    int n;
    vector<vector<int>>  dis;

    Graph(int _n) : n(_n), dis(n+1,vector<int>(n+1, 2e18)) {}

    void add_edge(int a, int b, int c){
        dis[a][b] = min(dis[a][b], c);
    }

    vector<vector<int>> get_dis(){
        for(int i=1; i<=n; i++) dis[i][i] = 0;
        
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        return dis;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,q;
    cin>>n>>m>>q;

    Graph g(n);

    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        g.add_edge(a,b,c);
        g.add_edge(b,a,c);
    }

    auto dis = g.get_dis();

    while(q--){
        int a,b;
        cin>>a>>b;
        cout << (dis[a][b] >= 1e18 ? -1 : dis[a][b]) << '\n';
    }

}