#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dr[] = {1,2,2,1,-1,-2,-2,-1};
int dc[] = {2,1,-1,-2,2,1,-1,-2};
int a[10][10];
int b[10][10];
bool vis[10][10];
bool found_ans = 0;

bool in(int r, int c){
    return r >= 1 && r <= 8 && c >= 1 && c <= 8;
}

void print_state(){
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int x, int r, int c){
    if(found_ans) return;
    
    a[r][c] = x;
    
    if(x == 64){
        found_ans = 1;
        print_state();
        return;
    }
    
    vector<pair<int,int>> order;

    for(int id=0; id<8; id++){
        int nr = r + dr[id];
        int nc = c + dc[id];

        if(in(nr,nc) && !a[nr][nc]){
            order.push_back({b[nr][nc], id});
        }
    }

    sort(order.begin(), order.end());

    for(auto [deg, id] : order){
        dfs(x+1, r+dr[id], c+dc[id]);
    }

    a[r][c] = 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            for(int k=0; k<8; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(in(nr,nc)) b[i][j]++;  
            }
        }
    }
    
    int r, c;
    cin>>c>>r;
    dfs(1, r, c);
}