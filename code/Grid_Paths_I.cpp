#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 1e9+7;

struct Martix{
    int n;
    vector<string> a;
    vector<vector<int>> dp;
    Martix(int _n): n(_n), dp(n+1, vector<int>(n+1,0)), a(n+1, string(n+1, ' ')) {}

    void input(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin>>a[i][j];
            }
        }
    }

    void fill_dp(){
        dp[1][1] = (a[1][1] == '.');
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == 1 && j == 1) continue;
                if(a[i][j] == '*') continue;
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%M;
            }
        }
    }

    void sol(){
        cout << dp[n][n] << '\n';
    }

};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    Martix martix(n);

    martix.input();

    martix.fill_dp();

    martix.sol();

}