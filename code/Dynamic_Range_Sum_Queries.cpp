#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Segt{
    struct Node{
        int sum;
    };

    int n;
    vector<Node> seg;
    Segt(vector<int> &a): n(a.size()-1), seg(4*n+5){
        build(1, n, 1, a);
    }

    void build(int l, int r, int id, vector<int> &a){

    }

    void set(int l, int r, int p, int x, int id){
        
    }

    int query(int l, int r, int ql, int qr, int id){

    }

    void set(int p, int x){
        set(1, n, p, x, 1);
    }

    int query(int l, int r){
        return query(1, n, l, r, 1);
    }
};

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n, q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];

    Segt segt(a);

    while(q--){
        int ty;
        cin>>ty;

        if(ty == 1){
            int k, u;
            cin>>k>>u;
            segt.set(k, u);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout << segt.query(l, r) << '\n';
        }
    }

}