#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    if(n == 1){
        cout << 1 << '\n';
        return 0;
    }
    else if(n<=3){
        cout << "NO SOLUTION\n";
        return 0;
    }
    else if(n==4){
        cout << "3 1 4 2\n";
        return 0;
    }

    for(int i=1; i<=n; i+=2){
        cout << i << ' ';
    }

    for(int i=2; i<=n; i+=2){
        cout << i << ' ';
    }
    
    cout << '\n';

}