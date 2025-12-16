#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> edge[100005];
int color[100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(color[i]) continue;

        color[i] = 1;
        q.push(i);
        while(q.size()){
            int v = q.front();
            q.pop();
            for(int next: edge[v]){
                if(!color[next]){
                    color[next] = 3 - color[v];
                    q.push(next);

                }else if(color[next] == color[v]){
                    cout<<"IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<color[i]<<(i == n ? '\n' : ' ');
    }

}