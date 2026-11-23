#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(int argc, char *argv[]){
    mt19937 rng(time(NULL));

    int n = rng() % 10;
    int m = rng() % 3;

    cout << n << ' ' << m << '\n';
    for(int i=0; i<n; i++){
        cout << rng()%100;
    }
    cout << '\n';

    while(m--){
        int l = rng() % n + 1;
        int r = rng() %n + 1;
        if(r < l) swap(l, r);
        cout << l << ' ' << r << '\n';
    }
}