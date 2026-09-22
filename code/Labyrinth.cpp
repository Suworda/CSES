#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
using pii = pair<int,int>;

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

struct Maze{
    int n, m;
    vector<string> a;
    pii S,T;

    Maze(int _n, int _m) : n(_n), m(_m), a(n+2, string(m+2, '#')) {}

    void read(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>a[i][j];  
                if(a[i][j] == 'A') S = {i,j};
                if(a[i][j] == 'B') T = {i,j};
            }
        }
    }

    optional<string> find_path(){
        vector<vector<bool>> vis(n+2, vector<bool>(m+2));
        vector<vector<pii>> pre(n+2, vector<pii>(m+2));
        vector<string> dir_from(n+2, string(m+2, 0));

        string dir = "DRUL";

        queue<pii> q;
        q.push(S);
        vis[S.first][S.second] = 1;

        while(q.size()){
            auto [r,c] = q.front(); q.pop();

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(!vis[nr][nc] && a[nr][nc] != '#'){
                    pre[nr][nc] = {r,c};
                    dir_from[nr][nc] = dir[i];
                    
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        auto [r,c] = T;
        if(!vis[r][c]) return nullopt;

        string path;
        while(a[r][c] != 'A'){
            path += dir_from[r][c];
            tie(r,c) = pre[r][c];
        }

        reverse(path.begin(), path.end());

        return path;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    Maze maze(n,m);

    maze.read();

    auto path = maze.find_path();

    if(!path){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << path->size() << '\n';
    cout << (*path) << '\n';

    
} 