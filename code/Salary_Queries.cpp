#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
struct Node{
    int l, r, m, cnt=0;
    Node *left=0, *right=0;
};
Node *root = new Node;
int p[200005];
 
void pull(Node *rt){
    if(!rt->left) rt->cnt = rt->right->cnt;
    else if(!rt->right) rt->cnt = rt->left->cnt;
    else rt->cnt = rt->left->cnt + rt->right->cnt;
}
 
void build(int l, int r, Node *&rt){
    if(rt) return;
    rt = new Node;
    rt->l = l;
    rt->r = r;
    rt->m = ((l+r)>>1);
}
 
void upd(int k, int v, Node *rt){
 
    rt->cnt += v;
    if(rt->l == rt->r){
        return;
    }
 
    // if(!rt->left && !rt->right){
        //     build(rt->l, m, rt->left);
        //     build(m+1, rt->r, rt->right);
        // }
        
    if(k <= rt->m){
        build(rt->l, rt->m, rt->left);
        upd(k, v, rt->left);
    }
    else{
        build(rt->m+1, rt->r, rt->right);
        upd(k, v, rt->right);
    }
}
 
int query(int ql, int qr, Node *rt){
    if(!rt || qr < rt->l || rt->r < ql) return 0;
 
    if(ql <= rt->l && rt->r <= qr){
        return rt->cnt;
    }
 
    return query(ql, qr, rt->left) + query(ql, qr, rt->right);
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    root->l = 1;
    root->r = 1e9;
    root->m = ((1000000001)>>1);
 
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>p[i];
        upd(p[i], +1, root);
    }
 
    char ty;
    int k,x;
    int a,b;
    while(q--){
        cin>>ty;
        if(ty == '!'){
            cin>>k>>x;
            upd(p[k], -1, root);
            p[k] = x;
            upd(p[k], +1, root);
        }
        else{
            cin>>a>>b;
            cout << query(a, b, root) << '\n';
        }
    }
 
 
 
}