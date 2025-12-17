#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
vector<int> nxt[MAXN+1];
int ans[MAXN+1];
bitset<MAXN+1> vis;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    int a;
    for(int i=2; i<=n; i++){
        cin>>a;
        nxt[a].push_back(i);
        nxt[i].push_back(a);
    }

    vector<int> order;
    queue<int> q;
    q.push(1);
    order.push_back(1);
    vis[1] = 1;

    while(q.size()){
        int v = q.front();
        q.pop();

        for(int u: nxt[v]){
            if(!vis[u]){
                order.push_back(u);
                vis[u] = 1;
                q.push(u);
            }
        }
    }
    reverse(order.begin(), order.end());

    vis.reset();
    for(int i=0; i<n; i++){
        int v = order[i];
        
        for(int u: nxt[v]){
            if(!vis[u]) ans[u]+=ans[v]+1;
        }
        vis[v] = 1;
    }

    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';

}