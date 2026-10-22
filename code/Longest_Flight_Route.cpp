#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> nxt[MAXN];
int indeg[MAXN];
int dp[MAXN];
int parent[MAXN];
int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    fill(parent+1, parent+1+n, -1);
    fill(dp+1, dp+1+n, -2e9);

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        nxt[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    dp[1] = 1;

    while(q.size()){
        int u = q.front();
        q.pop();
        for(int &v: nxt[u]){
            if(dp[u] > 0 && dp[u]+1 > dp[v]){
                dp[v] = dp[u]+1;
                parent[v] = u;
            }

            if(--indeg[v] == 0){
                q.push(v);
            }
        }
    }

    if(dp[n] < 0){
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    
    // parent[1] = -1;
    int x = n;
    vector<int> ans;
    while(x != -1){
        ans.push_back(x);
        x = parent[x];
    }

    cout<<dp[n]<<'\n';
    reverse(ans.begin(), ans.end());
    for(int &x: ans) cout<<x<<' ';



    

}