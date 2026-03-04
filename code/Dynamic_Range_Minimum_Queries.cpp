#include <bits/stdc++.h>
using namespace std;

struct Node{
    int v, l, r;
    Node *left, *right;
};

Node *root = new Node;
int n,q;
int a[200005];

void pull(Node *rt){
    Node *L = rt->left;
    Node *R = rt->right;
    rt->v = min(L->v, R->v);
}

void build(int l, int r, Node *rt){
    rt->l = l;
    rt->r = r;

    if(l == r){
        rt->v = a[l];
        return;
    }

    rt->left = new Node;
    rt->right = new Node;
    int m = (l+r)/2;
    build(l,m,rt->left);
    build(m+1, r, rt->right);
    pull(rt);
}

void upd(int p, int x, Node *rt){
    if(rt->l == p && rt->r == p){
        rt->v = x;
        return;
    }
    if(rt->r < p || p < rt->l) return;
    
    if(p < rt->r) upd(p,x,rt->left);
    if(rt->l < p) upd(p,x,rt->right);
    pull(rt);
}

int query(int ql, int qr, Node *rt){
    if(ql <= rt->l && rt->r <= qr) return rt->v;
    if(qr < rt->l || rt->r < ql) return 2e9;

    return min(query(ql, qr, rt->left), query(ql, qr,rt->right));

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    build(1,n,root);

    while(q--){
        int ty;
        cin>>ty;
        if(ty==1){
            int k, u;
            cin>>k>>u;
            upd(k,u,root);
            
        }else{
            int a, b;
            cin>>a>>b;
            cout<<query(a,b,root)<<'\n';
            
        }
    }

}


/*
#include <bits/stdc++.h>
using namespace std;

int n,q;
int a[200005];
int seg[800005];

void pull(int id){
    seg[id] = min(seg[id*2], seg[id*2+1]);
}

void build(int l, int r, int id){
    if(l == r){
        seg[id] = a[l];
        return;
    }
    
    int m = (l+r)/2;
    build(l,m,id*2); build(m+1,r,id*2+1);
    pull(id);
}

void upd(int l, int r, int p, int x, int id){
    if(l == p && r == p){
        a[p] = x;
        seg[id] = x;
        return;
    } 
    if(p < l || r < p) return;

    int m = (l+r)/2;
    if(l < p) upd(m+1, r, p, x, id*2+1);
    if(p < r) upd(l, m, p, x, id*2);
    pull(id);
}

int query(int l, int r, int ql, int qr, int id){
    if(ql <= l && r <= qr) return seg[id];
    if(r < ql || qr < l) return 2e9;

    int m = (l+r)/2;
    return min(query(l, m, ql, qr, id*2), query(m+1, r, ql, qr, id*2+1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    build(1,n,1);

    
    while(q--){
        int ty;
        cin>>ty;
        if(ty==1){
            int k, u;
            cin>>k>>u;
            upd(1,n,k,u,1);
            
        }else{
            int a, b;
            cin>>a>>b;
            cout<<query(1,n,a,b,1)<<'\n';
            
        }
    }
}
*/