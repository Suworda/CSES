#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        int n,a,b;
        cin>>n>>a>>b;

        int d = n-a-b;

        if(a+b > n || (a == 0 && b != 0) || (b == 0 && a != 0)){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(int i=1; i<=n; i++) cout << i << ' ';
        cout << '\n';

        for(int i=1; i<=d; i++) cout << i << ' ';
        for(int i=n-b+1; i<=n; i++) cout << i << ' ';
        for(int i=d+1; i<=d+a; i++) cout << i << ' ';
        cout << '\n';

    }

}