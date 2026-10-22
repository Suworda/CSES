#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n;
vector<int> nxt[MAXN];
int dis[MAXN];
bitset<MAXN> vis;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    int a,b;    
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }

    pair<int,int> ma;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while(q.size()){
        int v = q.front();
        q.pop();

        for(int u: nxt[v]){
            if(!vis[u]){
                dis[u] = dis[v]+1;
                vis[u] = 1;
                ma = max(ma, {dis[u],u});
                q.push(u);
            }
        }
    }
    //cout<<ma.second<<'\n';
    int ans=0;
    vis.reset();
    for(int i=1; i<=n; i++) dis[i] = 0;

    int st = ma.second;
    q.push(st);
    vis[st] = 1;

    while(q.size()){
        int v = q.front();
        q.pop();

        for(int u: nxt[v]){
            if(!vis[u]){
                dis[u] = dis[v]+1;
                vis[u] = true;
                ans = max(ans,dis[u]);
                q.push(u);
            }
        }
    }

    cout<<ans<<'\n';
}