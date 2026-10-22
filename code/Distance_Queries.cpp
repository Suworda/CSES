#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> nxt[MAXN];
int up[MAXN][33];
int dep[MAXN];
int in[MAXN];
int out[MAXN];
int n,q;
int now;

void dfs(int u){
    in[u] = now++;
    for(int &v: nxt[u]){
        if(!dep[v]){
            dep[v] = dep[u]+1;
            up[v][0] = u;
            dfs(v);
        }
    }
    out[u] = now++;
}

void build_up(){
    for(int i=1; i<=20; i++){
        for(int v=1; v<=n; v++){
            up[v][i] = up[up[v][i-1]][i-1];
        }
    }
}

bool valid(int a, int b){
    return (in[a] <= in[b] && out[a] >= out[b]);
}

int query(int a, int b){
    if(in[a] <= in[b] && out[a] >= out[b]) return abs(dep[a] - dep[b]);
    if(in[a] >= in[b] && out[a] <= out[b]) return abs(dep[a] - dep[b]);

    int x = a;
    for(int i=20; i>=0; i--){
        if(!valid(up[x][i], b)){
            x = up[x][i];
        }
    }
    x = up[x][0];
    return abs(dep[x] - dep[a]) + abs(dep[x] - dep[b]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;
    for(int i=1; i<=n; i++){
        up[i][0] = 1;
    }
    
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }

    dep[1]=1;
    dfs(1);
    build_up();

    while(q--){
        int a,b;
        cin>>a>>b;
        cout << query(a,b) << '\n';
    }
}