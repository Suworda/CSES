#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,x;
    cin>>n>>x;

    pair<int,int> a[n+1];
    for(int i=0; i<n; i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a, a+n);
    a[n]={2e9,n+1};

    for(int i=0; i<n; i++){
        for(int j=i+1, k=n; j<n-1; j++){
            long long targ = x - a[i].F - a[j].F;
            while(k-1 > j && a[k-1].F >= targ){
                k--;
            }

            //cout<<i<<' '<<j<<' '<<k<<'\n';

            if(a[k].F == targ){
                cout<<a[i].S<<' '<<a[j].S<<' '<<a[k].S<<'\n';
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE\n";

}