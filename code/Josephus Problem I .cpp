#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int> st;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        st.insert(i);
    }

    auto it=st.begin();
    while(st.size() ){
        it++;
        if(it==st.end()) it=st.begin();
        cout<< *it <<' ';
        it = st.erase(it);
        if(it==st.end()) it=st.begin();
    }
}
