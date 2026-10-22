#include <bits/stdc++.h>
using namespace std;
int n;
int x[5005];
long long sum[5005];
long long dp[5005][5005];

long long tot(int l, int r){
    return sum[r] - sum[l-1];
}

long long score(int l, int r){
    if(dp[l][r] != -9e18) return dp[l][r];
    if(l == r) return x[l];
    long long rst1 = x[l] + (tot(l+1,r) - score(l+1, r));
    long long rst2 = x[r] + (tot(l,r-1) - score(l, r-1));
    return dp[l][r] = max(rst1, rst2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=0; i<=5000; i++){
        for(int j=0; j<=5000; j++){
            dp[i][j] = -9e18;
        }
    }
    
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x[i];
        sum[i] = sum[i-1] + x[i];
    }
    cout<<score(1,n)<<'\n';

}