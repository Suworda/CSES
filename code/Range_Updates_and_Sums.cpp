#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int N = 200005;
int n,q;
int a[N];

struct Node{
    int l, r, v, tag_add=0, tag_set=0;
    Node *left=0, *right=0;
};

Node *root = new Node;

void pull(Node *rt){
    rt->v = rt->left->v + rt->right->v;
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
    build(l, m, rt->left);
    build(m+1, r, rt->right);
    pull(rt);
}

void push(Node *rt){
    Node *L = rt->left;
    Node *R = rt->right;

    if(rt->tag_set){
        L->tag_set = rt->tag_set;
        L->v = (L->r - L->l + 1) * rt->tag_set;
        L->tag_add = 0;
        R->tag_set = rt->tag_set;
        R->v = (R->r - R->l + 1) * rt->tag_set;
        R->tag_add = 0;
        rt->tag_set = 0;
    }

    L->tag_add += rt->tag_add;
    L->v += (L->r - L->l + 1) * rt->tag_add;
    R->tag_add += rt->tag_add;
    R->v += (R->r - R->l + 1) * rt->tag_add;
    rt->tag_add = 0;

}

void upd_add(int ql, int qr, int x, Node *rt){
    if(qr < rt->l || rt->r < ql) return;

    if(ql <= rt->l && rt->r <= qr){
        rt->tag_add += x;
        rt->v += x*(rt->r - rt->l + 1);
        return;
    }

    push(rt);
    upd_add(ql, qr, x, rt->left);
    upd_add(ql, qr, x, rt->right);
    pull(rt);
}

void upd_set(int ql, int qr, int x, Node *rt){
    if(qr < rt->l || rt->r < ql) return;

    if(ql <= rt->l && rt->r <= qr){
        rt->tag_set = x;
        rt->tag_add = 0;
        rt->v = x*(rt->r - rt->l + 1);
        return;
    }

    push(rt);
    upd_set(ql, qr, x, rt->left);
    upd_set(ql, qr, x, rt->right);
    pull(rt);
}

int query(int ql, int qr, Node *rt){
    if(qr < rt->l || rt->r < ql) return 0;

    if(ql <= rt->l && rt->r <= qr){
        return rt->v;
    }

    push(rt);
    int rst1 = query(ql, qr, rt->left);
    int rst2 = query(ql, qr, rt->right);

    return rst1 + rst2;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    build(1,n,root);
    
    while(q--){
        int ty;
        int a,b,x;
        cin>>ty;
        if(ty == 1){
            cin>>a>>b>>x;
            upd_add(a,b,x,root);
        }
        else if(ty == 2){
            cin>>a>>b>>x;
            upd_set(a,b,x,root);
            
        }
        else{
            cin>>a>>b;
            cout << query(a,b,root) << '\n';
            
        }
    }
}