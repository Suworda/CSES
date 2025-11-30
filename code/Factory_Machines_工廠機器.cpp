#include <bits/stdc++.h>
using namespace std;

int n,t;
int k[200005];

bool valid(long long x){
    long long cnt=0;
    for(int i=0; i<n; i++){
        cnt += x/k[i];
        if(cnt >= t) return true;
    }

    return false;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>t;
    for(int i=0; i<n; i++) cin>>k[i];

    long long ans=0;
    long long l=1, r=1e18;

    while(l <= r){
        long long mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout<<ans<<'\n';

}