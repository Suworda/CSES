#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int tot = a+b;
        int mi = min(a,b);
        int d = abs(a-b);
        if(tot % 3 == 0 && mi >= d){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

}