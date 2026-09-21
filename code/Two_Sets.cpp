#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    if(n % 4 == 0){
        cout << "YES\n";
        cout << n/2 << '\n';
        for(int i=1; i<=n; i+=4){
            cout << i << ' ' << i+3 << ' ';
        }
        cout << '\n' << n/2 << '\n';
        for(int i=2; i<=n; i+=4){
            cout << i << ' ' << i+1 << ' ';
        }
        cout << '\n';
    }
    else if(n % 4 == 3){
        cout << "YES\n";
        cout << n/2 << '\n';
        for(int i=0; i<=n; i+=4){
            if(i) cout << i << ' ' << i+3 << ' ';
            else cout << i+3 << ' ';
        }
        cout << '\n' << n/2+1 << '\n';
        for(int i=1; i<=n; i+=4){
            cout << i << ' ' << i+1 << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "NO\n";
    }

}