#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 1e9+7;

int dp[100005][105];
int a[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(i == 1){
            if(x){
                dp[i][x] = 1;
            }else{
                for(int j=1; j<=m; j++){
                    dp[i][j] = 1;
                }
            }
        }
        else{
            if(x){
                dp[i][x] = (dp[i-1][x-1] + dp[i-1][x] + dp[i-1][x+1])%M;
            }else{
                for(int j=1; j<=m; j++){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1])%M; 
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=m; i++){
        ans += dp[n][i];
    }

    cout << ans%M << '\n';

}