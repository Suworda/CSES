#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n;
vector<int> nxt[MAXN+1];
int ans[MAXN+1];

int dfs(int v){
    //ans[v] = sum(ans[u]+1)
    int rst=0;
    for(int u: nxt[v]){
        rst += dfs(u)+1;
    }
    return ans[v] = rst;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    int x;
    for(int i=2; i<=n; i++){
        cin>>x;
        nxt[x].push_back(i);
    }

    dfs(1);

    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
}