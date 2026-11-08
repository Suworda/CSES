#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
int s[5005];
int t[5005];
int dp[5005][5005];
pair<int,int> from[5005][5005];

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>s[i];
    for(int i=1; i<=m; i++) cin>>t[i];

    for(int i=1; i<=n; i++){
        for(int j=1 ;j<=m; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                from[i][j] = {i-1,j-1};
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    from[i][j] = {i-1, j};
                }
                else{
                    dp[i][j] = dp[i][j-1];
                    from[i][j] = {i, j-1};
                }
            }
        }
    }

    int r = n, c = m;

    vector<int> ans;
    while(r > 0 && c > 0){
        cerr << s[r] << ' ' << t[c] << '\n';
        if(s[r] == t[c]){
            ans.push_back(s[r]);
        }
        tie(r, c) = from[r][c];
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for(int x: ans) cout << x << ' ' ;
    cout << '\n';

}