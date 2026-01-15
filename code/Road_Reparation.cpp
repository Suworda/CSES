#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int v,u,w;

    bool operator< (const Edge &other) const{
        return w < other.w;
    }
};

int parent[100005];
Edge edge[200005];
int n,m;

int fpa(int x){
    if(parent[x] == x) return x;

    return parent[x] = fpa(parent[x]);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    iota(parent, parent+n, 0);
    
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> edge[i].v >> edge[i].u >> edge[i].w;
    }
    sort(edge, edge+m);

    long long ans=0;
    int cnt = 1;
    for(int i=0; i<m; i++){
        auto [a,b,w] = edge[i];
        // cout<<w<<'\n';
        int pa = fpa(a), pb = fpa(b);
        if(pa != pb){
            ans += w;
            parent[pa] = pb;
            cnt++;
        }
    }
    
    if(cnt == n) cout<<ans<<'\n';
    else cout<<"IMPOSSIBLE\n";

}
