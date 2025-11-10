#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    long long ans=(1LL << 60);

    for(int i=0; i<(1 << n); i++){
        long long w[2]={};
        for(int j=0; j<n; j++){
            w[(i>>j) & 1] +=a[j];
        }
        ans=min(ans, abs(w[0]-w[1]));
    }

    cout<<ans<<'\n';
}
