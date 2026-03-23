#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int x,n;
int p;
multiset<int> st;
multiset<int> ans;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>x>>n;
    st.insert(0);
    st.insert(x);
    ans.insert(x);
    for(int i=0; i<n; i++){
        cin>>p;
        auto it1 = st.lower_bound(p); it1--;
        auto it2 = st.lower_bound(p); 

        ans.erase(ans.find(*it2 - *it1));
        ans.insert(*it2 - p);
        ans.insert(p - *it1);
        st.insert(p);

        cout<<*ans.rbegin()<<' ';
    }
    
}
