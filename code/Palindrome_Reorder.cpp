#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

void print_ans(vector<int> cnt, int p){
    for(int i='A'; i<='Z'; i++){
        for(int j=0; j<cnt[i]/2; j++){
            cout << char(i);
        }
    }
    if(p) cout << char(p);
    for(int i='Z'; i>='A'; i--){
        for(int j=0; j<cnt[i]/2; j++){
            cout << char(i);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> cnt(128);
    string s;
    cin>>s;
    for(char c: s){
        cnt[c]++;
    }

    char p = 0;
    int x = 0;
    for(int i='A'; i<'Z'; i++){
        if(cnt[i]%2){
            p = i;
            x++;
        }
    }

    if(x > 1){
        cout << "NO SOLUTION\n";
    }
    else{
        print_ans(cnt, p);
    }

}