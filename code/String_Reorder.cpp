#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> cnt(129);
    string s;
    cin>>s;
    int n = s.size();

    for(char c: s){
        cnt[c]++;
    }

    vector<int> v(129);
    for(int i='A'; i<='Z'; i++){
        if(cnt[i]*2-1 > n){
            cout << -1 << '\n';
            return 0;
        }
        v[i] = cnt[i]*2-1;
    }

    string ans(n, ' ');
    int id = -1;

    int cur = n;
    bool flag = 0;
    while(cur){
        id++;
        if(!flag){
            for(int i='A'; i<='Z'; i++){
                if(cur == v[i]){
                    flag = 1;
                    for(int j = id; j<=n; j+=2){
                        ans[j] = char(i);
                    }
                    v[i] = 0;
                }
            }
        }
        
        for(int i='A'; i<='Z'; i++){
            if(v[i] > 0 && ans[id] == ' '){
                if(flag || id == 0){
                    v[i] -= 2;
                    ans[id] = char(i);
                    break;
                }

                if(i != ans[id-1]){
                    v[i] -= 2;
                    ans[id] = char(i);
                    break;
                }
            }
        }
        
        cur--;
    }

    cout << ans << '\n';

}