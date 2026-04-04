#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n,q;
int h[100005];
int ans[200005];
int l[200005];
int r[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>h[i];
    for(int i=1; i<=q; i++) cin>>l[i]>>r[i];

    vector<int> id(q+1);
    iota(id.begin()+1, id.end(), 1);
    sort(id.begin()+1, id.end(), [](int x, int y){
        return l[x] > l[y];
    });
    
    int stk[n+5]={};
    int top = 0;

    int x = 1;
    int cur = id[1];
    for(int i=n; i>=0; i--){
        while(x <= q && l[cur]-1 == i){
            auto it = lower_bound(stk+1, stk+top, r[cur], greater<>());
            ans[cur] = stk+top - it + 1;
            cur = id[++x];
        }

        while(top && h[i] >= h[stk[top]]){
            top--;
        }

        stk[++top] = i;
    }

    for(int i=1; i<=q; i++) cout<<ans[i]<<'\n';
}
