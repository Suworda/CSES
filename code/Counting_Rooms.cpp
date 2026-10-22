#include <bits/stdc++.h>
using namespace std;

int n,m;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
char a[1005][1005];
bool vis[1005][1005];
int ans;

bool valid(int r, int c){
    return r>=0 && r<n && c>=0 && c<m && a[r][c]!='#';
}

void bfs(int r, int c){
    ans++;
    queue<pair<int,int>> q;
    q.push({r,c});
    vis[r][c]=true;

    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(valid(nr,nc) && !vis[nr][nc]){
                q.push({nr,nc});
                vis[nr][nc] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(valid(i,j) && !vis[i][j]) bfs(i,j);
        }
    }

    cout<<ans<<'\n';

}