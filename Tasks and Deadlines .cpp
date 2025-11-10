#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define int long long

signed main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].x>>v[i].y;
    }
    sort(v.begin(), v.end());

    int curt=0;
    long long ans=0;
    for(int i=0; i<n; i++){
        curt+=v[i].x;
        ans+=v[i].y-curt;
    }

    cout<<ans<<'\n';
}

