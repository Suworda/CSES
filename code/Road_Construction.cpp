#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct DSU{
    int n;
    int mx = 1;
    int cnt;
    vector<int> parent;
    vector<int> sz;

    DSU(int _n) : n(_n), cnt(n), parent(n+1), sz(n+1, 1) {
        iota(parent.begin()+1, parent.end(), 1);
    }

    int find_p(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_p(parent[x]);
    }

    void merge(int a, int b){
        int pa = find_p(a);
        int pb = find_p(b);

        if(pa == pb) return;
        
        parent[pb] = pa;
        sz[pa] += sz[pb];
        sz[pb] = 0;

        cnt--;
        mx = max(mx, sz[pa]);
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    DSU dsu(n);

    while(m--){
        int a, b;
        cin>>a>>b;
        dsu.merge(a, b);
        cout << dsu.cnt << ' ' << dsu.mx << '\n';
    }



}