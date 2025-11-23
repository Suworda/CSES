#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

const int M=1000000007;

int f(ll a, ll b){
    if(b==0) return 1;

    ll x = f(a, b/2);

    if(b%2 == 0) return x * x %M;
    else return (x * x)%M * a %M;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
    //way 1 - recursion
        cout<<f(a,b)<<'\n';

    //way 2 - bit
//        long long cur=1;
//        if(b==0){
//            cout<<1<<'\n';
//            continue;
//        }
//
//        for(int i=__lg(b); i>=0; i--){
//            cur*=cur;
//            cur%=M;
//            if((b>>i) & 1 == 1){
//                cur*=a;
//                cur%=M;
//            }
//        }
//        cout<<cur<<'\n';
    }
}
