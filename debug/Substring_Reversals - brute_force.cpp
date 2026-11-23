#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;

    while(m--){
        int l, r;
        cin>>l>>r;
        l--; r--;
        reverse(s.begin()+l, s.begin()+r);
    }

    cout << s << '\n';

    

}