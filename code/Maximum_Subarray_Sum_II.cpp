#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,a,b;
int x[200005];
int sum[200005];
int dq[200005];
int front = 0, back = -1;
ll ans=-9e18;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>a>>b;
    for(int i=1; i<=n; i++) cin>>x[i];

    for(int i=1; i<=n; i++){
        sum[i] = sum[i-1] + x[i];

        if(front <= back && dq[front] <= i-b-1) front++;

        while(front <= back && i-a >= 0 && sum[i-a] < sum[dq[back]]){
            back--;
        }

        if(i-a >= 0){
            dq[++back] = i-a;
            ans = max(ans, sum[i] - sum[dq[front]]);
        }
    }

    cout<<ans<<'\n';

}