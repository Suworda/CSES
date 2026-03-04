#include <bits/stdc++.h>
using namespace std;

int n;   
int stk[200005];
int sn = 0;
int a[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    stk[sn++] = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        while(a[stk[sn-1]] >= a[i]){
            sn--;
        }
        cout<<stk[sn-1]<<' ';
        stk[sn++] = i;
    }

}