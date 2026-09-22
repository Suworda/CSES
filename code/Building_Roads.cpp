#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct DSU{
    int n;
    vector<int> parent;
    int cnt;
    
    DSU(int _n) : n(_n), parent(n+1), cnt(n) {
        for(int i=1; i<=n; i++){
            parent[i] = i;
        }
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
        cnt--;
    }
    
    vector<int> find_roots(){
        vector<int> dsu_pa;
        for(int i=1; i<=n; i++){
            if(find_p(i) == i) dsu_pa.push_back(i);
        }
        return dsu_pa;
    }

};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;

    DSU dsu(n);

    while(m--){
        int a,b;
        cin>>a>>b;
        dsu.merge(a,b);
    }

    vector<int> roots = dsu.find_roots();

    cout << roots.size()-1 << '\n';
    for(int i=1; i<roots.size(); i++){
        cout << roots[i-1] << ' ' << roots[i] << '\n';
    }
}