#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int x[200005];

bool valid(ll m){
    int rst = 1;
    ll cur = 0;
    for(int i=1; i<=n; i++){
        if(x[i] > m) return false;
        cur += x[i];
        if(cur > m){
            rst++;
            cur = x[i];
        }
    }

    return rst<=k;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>x[i];
    }

    ll l=0, r=4e18, ans=-1;
    while(l <= r){
        ll m = (l+r)/2;
        if(valid(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }

    cout<<ans<<'\n';

}