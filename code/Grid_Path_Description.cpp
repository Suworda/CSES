#include <bits/stdc++.h>
using namespace std;

int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};
char dir[50];
bool vis[9][9];
string s;
int ans = 0;

void dfs(int r, int c, int x){
    vis[r][c] = 1;

    if(r == 7 && c == 1){
        if(x == 48) ans++;

        vis[r][c] = 0;
        return;
    }

    if(vis[r][c-1] && vis[r][c+1] && !vis[r-1][c] && !vis[r+1][c]){
        vis[r][c] = 0;
        return;
    }
    if(!vis[r][c-1] && !vis[r][c+1] && vis[r-1][c] && vis[r+1][c]){
        vis[r][c] = 0;
        return;
    }
    
    if(s[x] != '?'){
        int nr = r+dr[dir[x]], nc = c+dc[dir[x]];
        if(!vis[nr][nc]) dfs(nr, nc, x+1);

    }else{
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(!vis[nr][nc]) dfs(nr, nc, x+1);
        }
    }

    vis[r][c] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<=8; i++){
        vis[0][i] = vis[i][0] = vis[8][i] = vis[i][8] = 1;
    }

    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'D') dir[i] = 0;
        else if(s[i] == 'R') dir[i] = 1;
        else if(s[i] == 'U') dir[i] = 2;
        else if(s[i] == 'L') dir[i] = 3;
        else dir[i] = -1;
    }
    vis[1][1] = 1;
    dfs(1,1,0);

    cout<<ans<<'\n';
}