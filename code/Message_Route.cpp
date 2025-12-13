#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100005];
bool vis[100005];
int from[100005];
int dis[100005];

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int> que;
    que.push(1);
    dis[1]=1;
    vis[1]=true;

    while(!que.empty()){
        int v = que.front();
        que.pop();
        //cout<<v<<'\n';
        for(int next: edge[v]){
            if(!vis[next]){
                que.push(next);
                vis[next] = true;
                from[next] = v;
                dis[next] = dis[v]+1;
            }
        }
    }

    if(dis[n] != 0){
        cout<<dis[n]<<'\n';

        int cur = n;
        vector<int> ans;
        while(dis[cur] != 0){
            ans.push_back(cur);
            cur = from[cur];
        }
        reverse(ans.begin(), ans.end());

        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<" \n"[i==ans.size()-1];
        }

    }else{
        cout<<"IMPOSSIBLE\n";
    }

    

}