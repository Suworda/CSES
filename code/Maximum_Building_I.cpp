#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,m;
char a[1005][1005];
int p[1005][1005];
int ans = 0;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>a[i][j];
        }
    }
        
    for(int j=1; j<=m; j++){
        int x = 0;
        for(int i=1; i<=n; i++){
            if(a[i][j] == '*') x = i;
            p[i][j] = x;
        }
    }

    for(int i=1; i<=n; i++){
        int stk[m+5]={};
        int top = 0;
        p[i][m+1] = 2e9;

        for(int j=1; j<=m+1; j++){

            while(top && i - p[i][j] <= i - p[i][stk[top]]){
                ans = max(ans, (i - p[i][stk[top]]) * (j - stk[top-1] -1));
                top--;
            }
            stk[++top] = j;
        }
    }

    cout<<ans<<'\n';

}