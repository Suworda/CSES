#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Seg{
    int l, r, v;
};

vector<Seg> dst(vector<Seg> v){
    int n = v.size();

    vector<int> d;
    for(int i=0; i<n; i++){
        d.push_back(v[i].l);
        d.push_back(v[i].r);
    }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());

    vector<Seg> rst;
    for(int i=0; i<n; i++){
        int x = lower_bound(d.begin(), d.end(), v[i].l) - d.begin() + 1;
        int y = lower_bound(d.begin(), d.end(), v[i].r) - d.begin() + 1;
        rst.push_back({x, y, v[i].v});
    }
    return rst;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector<Seg> v;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }

    v = dst(v);

    sort(v.begin(), v.end(), [](Seg &x, Seg &y){
        return x.r < y.r;
    });

    vector<int> dp(2*n+1);
    int id = 0;
    for(int i=1; i<=n*2; i++){
        dp[i] = dp[i-1];
        while(v[id].r == i){
            auto [l, r, p] = v[id];
            dp[i] = max(dp[i], dp[l-1] + p);
            id++;
        }
    }

    cout << dp[2*n] << '\n';
} 
