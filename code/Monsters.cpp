#include <bits/stdc++.h>
using namespace std;

int n,m;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};

char a[1005][1005];
int dis[1005][1005];
int t[1005][1005];
pair<int,int> from[1005][1005];
char dir[1005][1005];

char get_dir(int ty){
    if(ty==0) return 'D'; 
    if(ty==1) return 'U'; 
    if(ty==2) return 'R'; 
    if(ty==3) return 'L'; 
}

bool in(int r, int c){
    return r>=0 && r<n && c>=0 && c<m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    queue<pair<int,int>> qm, qa;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dis[i][j] = 2e9;
            t[i][j] = -1;

            cin>>a[i][j];
            if(a[i][j] == 'M'){
                dis[i][j] = 0;
                qm.push({i,j});

            }else if(a[i][j] == 'A'){
                t[i][j] = 0;
                qa.push({i,j});

            }
        }
    }
    
    while(!qm.empty()){
        auto [r,c] = qm.front();
        qm.pop();
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(in(nr,nc) && a[nr][nc]!='#' && dis[nr][nc] == 2e9){
                qm.push({nr,nc});
                dis[nr][nc] = dis[r][c]+1;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         printf("%2d", dis[i][j]);
    //     }
    //     cout<<'\n';
    // }


    string ans;
    while(!qa.empty()){
        auto [r,c] = qa.front();
        qa.pop();
        
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            
            if(!in(nr,nc)){
                cout<<"YES\n";
                cout<<t[r][c]<<'\n';;
                while(a[r][c] != 'A'){
                    ans += dir[r][c];
                    
                    nr = from[r][c].first;
                    nc = from[r][c].second;
                    r = nr;
                    c = nc;
                }
                reverse(ans.begin(), ans.end());
                cout<<ans<<'\n';
                return 0;
            }
            
            if(t[nr][nc] == -1 && a[nr][nc] != '#' && t[r][c]+1 < dis[nr][nc]){
                qa.push({nr,nc});
                t[nr][nc] = t[r][c]+1;
                from[nr][nc] = {r,c};
                dir[nr][nc] = get_dir(i);
            }
        }
        
    }

    cout<<"NO\n";

    // cout<<from[2][6].first<<' '<<from[2][6].second<<'\n';

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         printf("%d,%d%c ", i,j,dir[i][j]);
    //     }
    //     cout<<'\n';
    // }


}