#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int n;
vector<int> pre;
vector<int> in;
int cur_id = 0;
int change[100005];

void f(int l, int r, int rt_id){
    int m = change[rt_id];

    if(l <= m-1) f(l, m-1, pre[++cur_id]);
    if(m+1 <= r) f(m+1, r, pre[++cur_id]);
    cout<<rt_id<<' ';
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pre.push_back(x);
    }

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        in.push_back(x);
    }

    for(int i=0; i<n; i++){
        change[in[i]] = i;
    }

    f(0,n-1,pre[0]);

}