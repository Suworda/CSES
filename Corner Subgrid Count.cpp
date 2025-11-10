#pragma GCC target("popcnt")
#include <iostream>
#include <bitset>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    bitset<3000> b[n];
    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    long long ans=0;

    for(int i=0; i<n; i++){
        int cnt;
        for(int j=i+1; j<n; j++){
            cnt=(b[i] & b[j]).count();
            ans+=(cnt)*(cnt-1);
            //cout<<cnt<<'\n';
        }

    }
    cout<<ans/2<<'\n';
}

