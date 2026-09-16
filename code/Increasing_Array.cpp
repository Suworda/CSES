#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n;
    int last = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x <= last){
            ans += last - x;
        }
        last = max(last, x);
    }

    cout << ans << '\n';

}