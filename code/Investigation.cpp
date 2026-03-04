#include <bits/stdc++.h>
using namespace std;

struct Point{
    int u;
    long long cur;

    bool operator< (const Point &b) const{
        return cur > b.cur;
    }
};

const int M = 1e9 + 7;

long long dis[100005];
long long ways[100005];
int mi[100005], ma[100005];
bitset<100005> vis;
int n,m;
vector<pair<int,int>> nxt[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        dis[i] = 1e18;
        mi[i] = 1e9;
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        nxt[a].push_back({b,c});
    }

    priority_queue<Point> pq;
    pq.push({1,0});
    dis[1] = 0;
    ways[1] = 1;
    mi[1] = 0;
    ma[1] = 0;
    while(pq.size()){
        auto [u, cur] = pq.top();
        pq.pop();

        if(vis[u]) continue;
        vis[u] = 1;
        
        for(auto [v,w]: nxt[u]){
            if(cur + w == dis[v]){
                ways[v] += ways[u]; 
                ways[v]%=M;
                mi[v] = min(mi[v], mi[u]+1);
                ma[v] = max(ma[v], ma[u]+1);
                
            }else if(cur + w < dis[v]){
                dis[v] = cur+w;
                ways[v] = ways[u];
                mi[v] = mi[u]+1;
                ma[v] = ma[u]+1;
                pq.push({v, dis[v]});
            }
        }
    }

    cout<<dis[n]<<' '<<ways[n]<<' '<<mi[n]<<' '<<ma[n]<<'\n';

}