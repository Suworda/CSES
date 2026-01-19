#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
// int dp[101][1000005];
int dp[1000005];
int a[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,x;
    cin>>n>>x;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    // for(int i=1; i<=n; i++) dp[i][0] = 1;
    // for(int j=1; j<=x; j++){
    //     for(int i=1; i<=n; i++){
    //         dp[i][j] = dp[i-1][j];
    //         if(j - a[i] >= 0) dp[i][j] += dp[i][j-a[i]]; 
    //         dp[i][j]%=M;
    //     }
    // }

    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            if(j-a[i] >= 0) dp[j] += dp[j-a[i]];
            dp[j]%=M;
        }
    }
    cout<<dp[x]<<'\n';

}