#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
int X,a,b,c;
int x[10000005];
int dq[10000005];
int head = 0;
int tail = -1;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>k;
    cin>>X>>a>>b>>c;
    x[1] = X;
    for(int i=2; i<=n; i++){
        x[i] = (a*x[i-1] + b) % c;
    }

    for(int i=1; i<=k; i++){
        while(head <= tail && x[i] <= x[dq[tail]]){
            tail--;
        }
        dq[++tail] = i;
    }
    int cur = x[dq[head]];
    
    for(int i=k+1; i<=n; i++){
        if(head <= tail && dq[head] == i-k) head++;

        while(head <= tail && x[i] <= x[dq[tail]]){
            tail--;
        }

        dq[++tail] = i;
        cur ^= x[dq[head]];
    }

    cout<<cur<<'\n';



}