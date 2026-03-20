#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,k;
pair<int,int> seg[200005];
multiset<int> last;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int l,r;
        cin>>l>>r;
        seg[i] = {r,l};
    }    

    sort(seg, seg+n);

    int ans=0;
    for(int i=0; i<n; i++){
        auto [r,l] = seg[i];
        auto it = last.upper_bound(l);
        if(it != last.begin()){
            it--;
            last.erase(it);
            last.insert(r);
            ans++;

        }else if(last.size() < k){
            last.insert(r);
            ans++;
            
        }
    }

    cout<<ans<<'\n';
}