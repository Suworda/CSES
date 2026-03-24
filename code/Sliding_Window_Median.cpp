#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define sz size()

int n,k;
int x[200005];
multiset<int> l, r;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    int need = k/2 + 1;
    for(int i=1; i<=n; i++){
        cin>>x[i];
        r.insert(x[i]);
        if(r.sz > need){
            l.insert(*r.begin());
            r.erase(r.begin());
        }

        if(i > k){
            if(l.find(x[i-k]) != l.end()){
                l.erase(l.find(x[i-k]));

            }else{
                r.erase(r.find(x[i-k]));
                r.insert(*prev(l.end()));
                l.erase(prev(l.end()));
            }

        }
        if(i >= k) cout<<*r.begin()<<' ';
        
    }
    
}
