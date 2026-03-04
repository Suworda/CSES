#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;   
int stk[200005];
int sn = 0;
int k[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>k[i];
    k[0] = -1;
    stk[sn++] = 0;
    long long ans = 0;

    for(int i=1; i<=n+1; i++){
        while(k[stk[sn-1]] >= k[i]){
            int h = k[stk[sn-1]];
            sn--;
            int l = stk[sn-1];
            int r = i;
            int w = r - l - 1;

            ans = max(ans, w*h);
        }
        stk[sn++] = i;
    }

    cout<<ans<<'\n';

}