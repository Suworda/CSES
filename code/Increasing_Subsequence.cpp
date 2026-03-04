#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin>>n;
    int x;
    for(int i=0; i<n; i++){
        cin>>x;
        if(i == 0 || x > dp.back()){
            dp.push_back(x);
        
        }else{
            auto it = lower_bound(dp.begin(), dp.end(), x);
            int idx = it - dp.begin();
            dp[idx] = x;
        }
    }

    cout<<dp.size()<<'\n';
}