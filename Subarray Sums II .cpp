#include <bits/stdc++.h>
using namespace std;

map<long long,int> cnt;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cnt[0]=1;

    int n,x;
    cin>>n>>x;
    int a[n+1];

    long long sum=0;
    long long ans=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum+=a[i];
        ans+=cnt[sum-x];
        cnt[sum]++;
    }


    cout<<ans<<'\n';

}
