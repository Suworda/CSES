#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int q;

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>q;
    while(q--){
        int r,c;
        cin>>r>>c;
        int x = max(r,c);
        int ans = x*x - (x-1);

        if(r < c){
            if(x%2 == 1){
                cout << ans + (x-r);
            }
            else{
                cout << ans - (x-r);
            }
        }
        else{
            if(x%2 == 0){
                cout << ans + (x-c);
            }
            else{
                cout << ans - (x-c);
            }
        }

        cout << '\n';
        // c++;
    }

}