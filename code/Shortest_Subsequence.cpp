#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

string s;
int n;
int nxt[1000005][4];

int change(char c){
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
    if(c == 0) return 'A';
    if(c == 1) return 'C';
    if(c == 2) return 'G';
    if(c == 3) return 'T';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>s;
    n = s.size();

    for(int i=0; i<4; i++) nxt[n][i] = n;
    
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<4; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][change(s[i])] = i;
    }
    
    // cout<<"ok\n";
    // return 0;
    
    int x = -1;
    string ans;
    while(x < n){
        int rst=0;
        int mx = x;
        for(int i=0; i<4; i++){
            if(nxt[x+1][i] > mx){
                rst = i;
                mx = nxt[x+1][i];
            }
        }

        x = nxt[x+1][rst];
        ans += change(rst);
    }

    // cout<<nxt[1][change('C')];
    cout<<ans<<'\n';





}