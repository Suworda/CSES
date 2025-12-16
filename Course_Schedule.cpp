#include <bits/stdc++.h>
using namespace std;

vector<int> nxt[100005];
vector<int> ans;
int indeg[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        nxt[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i] == 0){
            q.push(i);
            ans.push_back(i);
        }
    }

    while(q.size()){
        int v = q.front();
        q.pop();
        
        for(int u: nxt[v]){
            if(--indeg[u] == 0){
                q.push(u);
                ans.push_back(u);
            }
        }
    }

    if(ans.size() == n){
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<(i == n-1 ? '\n' : ' ');
    }
    else cout<<"IMPOSSIBLE\n";
}