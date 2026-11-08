#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
bitset<100005> dp;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    int cnt = 0;
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        for(int j=100000; j>=0; j--){
            if(dp[j]){
                if(dp[j+x] == 0) cnt++;
                dp[j+x] = 1;
            }
        }
    }

    cout << cnt << '\n';
    for(int i=1; i<=100005; i++){
        if(dp[i]) cout << i << ' ' ;
    }
    cout << '\n';

}