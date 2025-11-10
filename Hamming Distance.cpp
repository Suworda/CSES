#pragma GCC target("popcnt")
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n]={};
    char c;
    for(int i=0; i<n; i++){
        for(int j=k-1; j>=0; j--){
            cin>>c;
            if(c=='1'){
                a[i]+=(1<<j);
            }
        }
    }

    int ans=30;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            ans=min(ans,__builtin_popcount(a[i] ^ a[j]));
        }
    }

    cout<<ans<<'\n';
}
