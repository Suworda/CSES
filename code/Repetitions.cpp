#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    string s;
    cin>>s;
    char last = 0;
    int ans = 0;
    int cur = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == last) cur++;
        else{
            cur = 1;
            last = s[i];
        }
        ans = max(ans, cur);
    }

    cout << ans << '\n';

}