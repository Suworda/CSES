#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1000001;

int cnt[MAX_V+1];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        cnt[x]++;
    }

    for(int i=MAX_V; i>=0; i--){
        int apr=0;
        for(int j=i; j<=MAX_V; j+=i){
            apr+=cnt[j];
        }
        if(apr>=2){
            cout<<i<<'\n';
            return 0;
        }
    }



}
