#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[] = {-1,-2,-2,-1,1,2,2,1};
int dc[] = {2,1,-1,-2,-2,-1,1,2};
int n;

bool in(int r, int c){
    return r >= 1 && r <= n && c >= 1 && c <= n;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    vector<vector<int>> ans(n+2, vector<int>(n+2));
    vector<vector<bool>> vis(n+2, vector<bool>(n+2));

    queue<pair<int,int>> q;
    q.push({1,1});
    ans[1][1] = 0;
    vis[1][1] = 1;
    while(q.size()){
        auto [r,c] = q.front(); q.pop();

        for(int i=0; i<8; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(in(nr,nc) && !vis[nr][nc]){
                ans[nr][nc] = ans[r][c] + 1;
                q.push({nr,nc});
                vis[nr][nc] = 1;
            }
        }

    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << ans[i][j] << ' ' ;
        }
        cout << '\n';
    }


}