#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Graph{
    int n;
    vector<int> nxt;
    vector<vector<int>> jp;

    Graph(int _n): n(_n), nxt(n+1), jp(n+1, vector<int>(31)) {};

    void add_edge(int a, int b){
        nxt[a] = b;
    }

    void init_jump(){
        for(int i=1; i<=n; i++) jp[i][0] = nxt[i];

        for(int j=1; j<=30; j++){
            for(int i=1; i<=n; i++){
                jp[i][j] = jp[jp[i][j-1]][j-1];
            }
        }
    }

    void get_ans(int &x, int k){
        for(int i=0; i<=30; i++){
            if((k>>i) & 1) x = jp[x][i];
        }
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin>>n>>q;

    Graph g(n);
    for(int i=1; i<=n; i++){
        int t;
        cin>>t;
        g.add_edge(i,t);
    }
    
    g.init_jump();
    
    while(q--){
        int x,k;
        cin>>x>>k;
        g.get_ans(x,k);
        cout << x << '\n';
    }

}