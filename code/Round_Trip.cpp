#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector<int> nxt[MAXN+5];
int dep[MAXN+5];
int from[MAXN+5];
bitset<MAXN+5> vis;
vector<int> path1, path2;
vector<int> ans;

void print(int x, int y){
    while(x != y){
        //cout<<x<<' '<<y<<'\n';
        if(dep[x] > dep[y]){
            path1.push_back(x);
            x = from[x];
        }else{
            path2.push_back(y);
            y = from[y];
        }
    }

    ans.push_back(x);
    reverse(path1.begin(), path1.end());
    for(int v: path1) ans.push_back(v);

    for(int v: path2) ans.push_back(v);
    ans.push_back(x);

    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<(i==ans.size()-1 ? '\n' : ' ');
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            q.push(i);
            vis[i]=1;
        }
        while(q.size()){
            int v = q.front();
            q.pop();

            for(int u: nxt[v]){
                if(vis[u] && from[v] != u){
                    print(u,v);
                    return 0;

                }else if(!vis[u]){
                    vis[u]=1;
                    from[u]=v;
                    dep[u] = dep[v]+1;
                    q.push(u);
                }
            }
        }
    }

    cout<<"IMPOSSIBLE"<<'\n';



}