#include <bits/stdc++.h>
using namespace std;
#define lid id*2
#define rid id*2+1
const long long INF = -2e18;

struct Node{
    long long sum, mx;
};

int n,q;
int a[200005];
Node seg[800005];

Node merge(Node L, Node R){
    return {L.sum + R.sum, max(L.mx, L.sum+R.mx)};
}

void pull(int id){
    seg[id] = merge(seg[lid], seg[rid]);
}

void build(int l, int r, int id){
    if(l == r){
        seg[id].sum = a[l];
        seg[id].mx = max(0, a[l]);
        return;
    }

    int m = (l+r)/2;
    build(l, m, lid);
    build(m+1, r, rid);
    pull(id);
}

Node query(int l, int r, int ql, int qr, int id){
    if(ql <= l && r <= qr) return {seg[id].sum , seg[id].mx};

    int m = (l+r)/2;
    if(qr <= m) return query(l, m, ql, qr, lid);
    if(m < ql) return query(m+1, r, ql, qr, rid);

    return merge(query(l, m, ql, qr, lid), query(m+1, r, ql, qr, rid));
}

void upd(int l, int r, int p, int x, int id){
    if(l == p && r == p){
        seg[id] = {x, max(0,x)};
        return;
    }

    int m = (l+r)/2;
    if(p <= m) upd(l, m, p, x, lid);
    else upd(m+1, r, p, x, rid);
    pull(id);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=1; i<=n; i++) cin>>a[i];

    build(1,n,1);

    while(q--){
        int ty,k,u,a,b;
        cin>>ty;
        if(ty == 1){
            cin>>k>>u;
            upd(1,n,k,u,1);
        }else{
            cin>>a>>b;
            cout<<query(1,n,a,b,1).mx<<'\n';
        }
    }

}