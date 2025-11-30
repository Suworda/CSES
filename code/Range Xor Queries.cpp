#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    int a[n+1];
    int pre_xor[n+1]={};
    for(int i=1; i<=n; i++){
        cin>>a[i];
        pre_xor[i]=pre_xor[i-1]^a[i];
    }

    while(q--){
        int l,r;
        cin>>l>>r; l--;

        cout<<(pre_xor[r] ^ pre_xor[l])<<'\n';
    }
}
