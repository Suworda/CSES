#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,x;
int a[1005];
map<int,pair<int,int>> p;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n>>x;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int k=3; k<n; k++){
        for(int i=1; i<k-1; i++){
            p[a[i] + a[k-1]] = {i,k-1};
        }

        for(int l=k+1; l<=n; l++){
            auto it = p.find(x-a[k]-a[l]);
            if(it != p.end()){
                cout<<it->second.first<<' '<<it->second.second<<' '<<k<<' '<<l<<'\n';
                return 0;
            }
        }

    }
    cout<<"IMPOSSIBLE\n";

}