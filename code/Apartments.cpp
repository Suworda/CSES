#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m,k;
int a[200005], b[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>k;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);

    int x = 0, y = 0;
    int ans=0;
    while(x < n && y < m){
        if(abs(a[x] - b[y]) <= k){
            ans++;
            x++; y++;

        }else{
            if(a[x] < b[y]) x++;
            else y++;
            
        }
    }

    cout<<ans<<'\n';

}