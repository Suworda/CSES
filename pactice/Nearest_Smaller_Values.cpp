#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> a(n+2);
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> stk;
    vector<int> ans(n+2);
    stk.reserve(n+2);
    for(int i=1; i<=n; i++){
        while(stk.size() && a[stk.back()] >= a[i]){
            stk.pop_back();
        }

        if(stk.size()) ans[i] = stk.back();

        stk.push_back(i);
    }

    for(int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';

}