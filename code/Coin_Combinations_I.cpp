#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;
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

    dp[0] = 1;
    for(int i=1; i<=x; i++){
        for(int j=1; j<=n; j++){
            if(i - a[j] >= 0) dp[i] += dp[i-a[j]];
            dp[i]%=M;
        }
    }
    cout<<dp[x]<<'\n';

}