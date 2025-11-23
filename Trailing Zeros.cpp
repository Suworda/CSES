#include <bits/stdc++.h>
using namespace std;

int f(int x){
    if(x < 5) return 0;
    return x/5 + f(x/5);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin>>n;
//    int ans=0;
    //way 1 - while
//    while(n>=5){
//        ans+=(n/5);
//        n/=5;
//    }
//    cout<<ans<<'\n';


    //way 2 - recursion
    cout << f(n) << '\n';
}
