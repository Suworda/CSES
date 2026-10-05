#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

ll pow_10(int b){
    ll x = 1;
    while(b--){
        x *= 10;
    }

    return x;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v;
    for(int i=0; i<17; i++){
        v.push_back((i+1)*9*pow_10(i));
    }
    int q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        ll start = 1;
        ll x = 1;
        for(int i=0; i<v.size(); i++){
            if(k - v[i] <= 0) break;
            start = pow_10(i+1);
            x = i+2;
            k -= v[i];
        }

        k--;
        string s = to_string(start + k/x);
        cout << s[k%x] << '\n';

    }

}