#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void _fill(vector<string> &a, int r, int c){
    for(int i='A'; i<='D'; i++){
        if(a[r][c] == i || a[r-1][c] == i || a[r][c-1] == i) continue;
        a[r][c] = i;
        break;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    vector<string> a(n+1, string(m+1,' '));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            _fill(a, i, j);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << a[i][j];
        }
        cout << '\n';
    }

}