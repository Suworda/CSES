#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

mt19937 rng(time(NULL));

struct Treap{
    struct Node{
        Node *l=0, *r=0;
        int sz=1, pri;
        char c;

        Node(char _c): c(_c), pri(rng()){}

        void pull(){
            sz = 1;
            for(auto i:{l,r}){
                if(i){
                    sz += i->sz;
                }
            }
        }
    };

    Node *root = nullptr;

    int size(Node *rt){
        return rt ? rt->sz : 0;
    }

    pair<Node*, Node*> split(Node *rt, int k){
        if(!rt) return {nullptr, nullptr};

        if(size(rt->l)+1 <= k){
            auto [a,b] = split(rt->r, k - (size(rt->l)+1));

            rt->r = a;
            rt->pull();

            return {rt, b};
        }
        else{
            auto [a,b] = split(rt->l, k);

            rt->l = b;
            rt->pull();

            return {a, rt};
        }
    }

    Node *merge(Node *a, Node *b){
        if(!a) return b;
        if(!b) return a;

        if(a->pri > b->pri){
            a->r = merge(a->r, b);
            a->pull();
            return a;
        }
        else{
            b->l = merge(a, b->l);
            b->pull();
            return b;
        }
    }

    void upd(int l, int r){
        auto [ab, c] = split(root, r);
        auto [a,b] = split(ab, l-1);

        root = merge(merge(a, c), b);
    }

    void insert(int p, char x){
        auto [a, b] = split(root, p-1);
        root = merge(merge(a, new Node(x)), b);
    }

    void append(char x){
        root = merge(root, new Node(x));
    }

    char query(int p){
        auto [ab,c] = split(root, p);
        auto [a, b] = split(ab, p-1);

        char ans = b->c;

        root = merge(merge(a, b), c);

        return ans;
    }

    void dfs(Node *rt){
        if(!rt) return;
        dfs(rt->l);
        cout << rt->c;
        dfs(rt->r);
    }

};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin>>n>>m;

    Treap trp;

    for(int i=1; i<=n; i++){
        char c;
        cin>>c;
        trp.append(c);
    }

    while(m--){
        int l, r;
        cin>>l>>r;
        trp.upd(l, r);
    }

    trp.dfs(trp.root);
    cout << '\n';
}