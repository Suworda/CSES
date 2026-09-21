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
    int ans = 1;
    while(n--){
        ans <<= 1;
        ans %= M;
    }

    cout << ans << '\n';

}