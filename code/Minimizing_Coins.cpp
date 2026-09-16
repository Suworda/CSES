#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,x;
int c[105];
int dp[1000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>x;
    for(int i=1; i<=n; i++) cin>>c[i];

    for(int i=1; i<=x; i++) dp[i] = 2e9;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=x; j++){
            if(j - c[i] >= 0) dp[j] = min(dp[j], dp[j-c[i]]+1);
        }
    }

    if(dp[x] > 1e9) cout << -1 << '\n';
    else cout << dp[x] << '\n';

    

}