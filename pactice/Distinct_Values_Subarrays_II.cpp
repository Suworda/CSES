#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

vector<int> dist(vector<int> &a){
    vector<int> d = a;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());

    vector<int> b{-1};
    for(auto x: a){
        auto it = lower_bound(d.begin(), d.end(), x);
        b.push_back(it-d.begin());
    }
    return b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    a = dist(a);
    vector<int> cnt(n+1);
    int cur = 0;
    
    int ans = 0;
    int r = 0;
    for(int l=1; l<=n; l++){
        while(r+1 <= n && cur + (cnt[a[r+1]] == 0) <= k){
            cur += (cnt[a[r+1]] == 0);
            cnt[a[r+1]]++;
            r++;
        }

        ans += r - l + 1;

        if(cnt[a[l]] == 1){
            cur--;
        }
        cnt[a[l]]--;
    }

    cout << ans << '\n';

}