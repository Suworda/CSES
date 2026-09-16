#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    while(n != 1){
        cout << n << ' ';
        if(n%2 == 0) n/=2;
        else n = 3*n+1;
    }
    cout << 1 << '\n';

}