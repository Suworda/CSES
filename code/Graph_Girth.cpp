#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2500;
int n,m;
int ans=2e9;
vector<int> nxt[MAXN+1];
int from[MAXN+1];
int dis[MAXN+1];
bitset<MAXN+1> vis;

void init(){
    vis.reset();
    for(int i=1; i<=n; i++) dis[i] = 2e9;
    for(int i=1; i<=n; i++) from[i] = -1;
}

void update_ans(int x, int y){
    ans = min(ans, dis[x] + dis[y] +1);
}

void bfs(int st){
    init();

    queue<int> q;
    q.push(st);
    vis[st] = 1;
    dis[st] = 0;

    while(q.size()){
        int v = q.front();
        q.pop();

        for(int u: nxt[v]){
            if(vis[u]){
                if(from[v] != u){
                    update_ans(u,v);
                }

            }else{
                vis[u] = 1;
                from[u] = v;
                dis[u] = dis[v]+1;
                q.push(u);
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }
    
    for(int i=1; i<=n; i++){
        bfs(i);
    }
    if(ans == 2e9) ans=-1;
    
    cout<<ans<<'\n';
}