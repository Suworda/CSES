#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> nxt[MAXN];
int up[MAXN][33];
bitset<MAXN> vis;
int n,q;
int in[MAXN];
int out[MAXN];
int now=1;

void init_up(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<32; j++){
            up[i][j] = 1;
        }
    }
}

void dfs(int u){
    in[u] = now++;
    for(int &v: nxt[u]){
        if(!vis[v]){
            vis[v] = 1;
            up[v][0] = u;
            dfs(v);
        }
    }
    out[u] = now++;
}

void build_up(){
    init_up();
    vis[1] = 1;
    dfs(1);

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
    if(in[a] <= in[b] && out[a] >= out[b]) return a;
    if(in[a] >= in[b] && out[a] <= out[b]) return b;

    for(int i=20; i>=0; i--){
        if(!valid(up[a][i], b)){
            a = up[a][i];
        }
    }
    a = up[a][0];

    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=2; i<=n; i++){
        int x;
        cin>>x;
        nxt[x].push_back(i);
    }

    build_up();

    while(q--){
        int a,b;
        cin>>a>>b;
        cout << query(a,b) << '\n';
    }


    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<5; j++){
    //         cout<<i<<' '<<j<<' '<<up[i][j]<<'\n';
    //     }
    // }
}
