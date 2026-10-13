#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,x;
    cin>>n>>x;
    vector<int> h(n+1), s(n+1);

    for(int i=1; i<=n; i++) cin>> h[i];
    for(int i=1; i<=n; i++) cin>> s[i];

    for(int i=1; i<=n; i++){
        for(int j=x; j>=0; j--){
            if(j - h[i] >= 0) dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
        }
    }

    cout << dp[x] << '\n';
}