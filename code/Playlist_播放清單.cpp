#include <bits/stdc++.h>
using namespace std;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    set<int> st;
    vector<int> a(n);
    for(int &x: a) cin>>x;

    int ans=0;
    for(int l=0, r=0; l<n; l++){
        while(r<n && !st.count(a[r])){
            st.insert(a[r++]);
        }
        //cout<<r-l<<'\n';
        ans = max(ans, r-l);
        st.erase(a[l]);
        
    }

    cout<<ans<<'\n';
}