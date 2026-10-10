#include <iostream>
#include <vector>
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<int> lis;
    int x;
    for(int i=1; i<=n; i++){
        cin>>x;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if(it == lis.end()) lis.push_back(x);
        else (*it) = x;
    }

    cout << lis.size() << '\n';
}