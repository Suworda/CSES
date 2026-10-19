#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int M = 1e9+7;

ll dp[1000005][2];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i=3; i<=1000000; i++){
        dp[i][0] = (2*dp[i-1][0] + dp[i-1][1])%M; //f(i-1, "001");
        dp[i][1] = (1*dp[i-1][0] + 4*dp[i-1][1])%M; //f(i-1, "11101");
    }

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n == 1){
            cout << 2 << '\n';
            continue;
        }

        ll ans = (3*dp[n][0] + 5*dp[n][1])%M;

        cout << ans << '\n';

    }
}