#include <bits/stdc++.h>
using namespace std;

void sol(){
    int n,k;
    cin>>n>>k;
    if(k*k < n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for(int i=n; i>=1; i-=k){
        for(int j=k-1; j>=0; j--){
            if(i-j >= 1) cout<<i-j<<' ';
        }
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--) sol();

}