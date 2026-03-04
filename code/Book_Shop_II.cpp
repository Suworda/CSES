#include <bits/stdc++.h>
using namespace std;

int n,x; 
int h[1005], s[1005], k[1005];
// long long dp[105][100005];
long long dp[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>x;
    for(int i=1; i<=n; i++) cin>>h[i];
    for(int i=1; i<=n; i++) cin>>s[i];
    for(int i=1; i<=n; i++) cin>>k[i];

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=x; j++){
    //         dp[i][j] = dp[i-1][j];
    //         for(int cnt=1; cnt<=k[i]; cnt++){
    //             if(j-h[i]*cnt >= 0){
    //                 dp[i][j] = max(dp[i][j], dp[i-1][j-h[i]*cnt] + s[i]*cnt);

    //                 // cout<<i<<' '<<j<<' '<<cnt<<' '<<dp[i][j]<<'\n';
    //             }
    //         }
    //     }
    // }
    // cout<<dp[n][x]<<'\n';

    for(int i=1; i<=n; i++){
        for(int p=1; p<=k[i]; p<<=1){
            for(int j=x; j>=0; j--){
                if(j-h[i]*p >= 0) dp[j] = max(dp[j], dp[j-h[i]*p] + s[i]*p);
            }
            k[i] -= p;

        }
        if(k[i] > 0){
            for(int j=x; j>=0; j--){
                if(j-h[i]*k[i] >= 0) dp[j] = max(dp[j], dp[j-h[i]*k[i]] + s[i]*k[i]);
            }
        }
    }
    cout<<dp[x]<<'\n';
}