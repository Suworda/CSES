#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 100005;
int n,m;
vector<int> nxt[N];
int vis[N];
int from[N];
vector<int> ans;

void dfs(int u, int pa){
    if(vis[u] == 1) return;
    
    if(vis[u] == 2){
        int x = pa;
        ans.push_back(u);
        while(x != u){
            ans.push_back(x);
            x = from[x];
        }
        ans.push_back(u);
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<'\n';
        for(auto x: ans) cout<<x<<' ';
        exit(0);
    }

    from[u] = pa;
    vis[u] = 2; 

    for(int v: nxt[u]){
        dfs(v,u);
    }
    vis[u] = 1;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        nxt[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        dfs(i,0);
    }

    cout<<"IMPOSSIBLE\n";
    
}
