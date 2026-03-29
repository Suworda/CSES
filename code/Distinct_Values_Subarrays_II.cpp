#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
int a[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];

    ll ans = 0;
    int r = -1;
    int cnt=0;
    multiset<int> st;
    for(int l=0; l<n; l++){
        while(r+1 < n && (cnt + !st.count(a[r+1])) <= k){
            cnt += !st.count(a[r+1]);
            st.insert(a[r+1]);
            r++;
        }

        ans += max(0ll, r-l+1);
        st.erase(st.find(a[l]));
        if(st.find(a[l]) == st.end()) cnt--;
    }
    
    cout<<ans<<'\n';

}