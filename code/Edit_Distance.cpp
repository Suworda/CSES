#include <bits/stdc++.h>
using namespace std;

string s, t;
int n,m;
int dp[5005][5005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s>>t;
    n = s.size();
    m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    for(int i=0; i<=n; i++) dp[i][0]=i;
    for(int i=0; i<=m; i++) dp[0][i]=i;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1];

            }else{
                dp[i][j] = 1 + min({
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1]
                });
            }
        }
    }

    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=m; j++){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    cout<<dp[n][m]<<'\n';

}