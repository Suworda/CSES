#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int dp[1000005];
bitset<1000005> vis;

int dfs(int n){
    if(vis[n]) return dp[n];
    ll rst = 2e9;
    string s = to_string(n);
    for(char c:s){
        if(c == '0') continue;
        rst = min(rst, dfs(n - (c - '0')) + 1);
    }

    vis[n] = 1;
    return dp[n] = rst;
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    vis[0] = 1;
    cout << dfs(n) << '\n';

}