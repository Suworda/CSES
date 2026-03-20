#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
multiset<int> last;
int ans=0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=1; i<=n; i++){
        int k;
        cin>>k;
        auto it = last.upper_bound(k);
        if(it == last.end()){
            ans++;
            last.insert(k);

        }else{
            last.erase(it);
            last.insert(k);
        }
    }

    cout<<ans<<'\n';
}