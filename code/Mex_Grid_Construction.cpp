#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int get_rst(vector<vector<int>> a, int r, int c){
    for(int x = 0; x<=100; x++){
        bool ok = 1;
        for(int i=r; i>=1; i--){
            if(a[i][c] == x) ok = 0;
        }
        for(int j=c; j>=1; j--){
            if(a[r][j] == x) ok = 0;
        }
        if(ok){
            return x;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<vector<int>> a(n+2, vector<int>(n+2, -1));

    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            a[i][j] = get_rst(a,i,j);
        }
        for(int j=i+1; j<=n; j++){
            a[j][i] = get_rst(a,j,i);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

}