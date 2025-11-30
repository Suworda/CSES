#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    multiset<int> mst;

    int h;
    for(int i=0; i<n; i++){
        cin>>h;
        mst.insert(h);
    }

    int t;
    for(int i=0; i<m; i++){
        cin>>t;
        auto it = mst.upper_bound(t);

        if(it == mst.begin()){
            cout<<-1<<'\n';
        }else{
            it--;
            cout<< *it <<'\n';
            mst.erase(mst.find(*it));
        }
    }
}


