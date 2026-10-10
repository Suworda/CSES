#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 1e9 + 7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> dp(1000005);

    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(i-j >= 0) dp[i] += dp[i-j];
            dp[i] %= M;
        }
    }
    
    cout << dp[n] << '\n';
} 