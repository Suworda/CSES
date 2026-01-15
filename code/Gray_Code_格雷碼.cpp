#include <bits/stdc++.h>
using namespace std;

int n;
bool ans[17][100000];

void f(int n, int l, int r, bool need_reverse){
    if(n == 0) return;

    int m = (l+r)/2;
    if(!need_reverse){
        for(int i=m+1; i<=r; i++) ans[n][i]=1;
    }else{
        for(int i=l; i<=m; i++) ans[n][i]=1;
    }
    f(n-1, l, m, 0);
    f(n-1, m+1, r, 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    f(n, 1, (1<<n), 0);

    for(int i=1; i<=(1<<n); i++){
        for(int j=n; j>=1; j--){
            cout<<ans[j][i];
        }
        cout<<'\n';
    }
}