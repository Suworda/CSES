#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

mt19937 rng(time(NULL));

struct Treap{
    struct Node{
        Node *l=0, *r=0;
        int sz=1, pri;
        bool rev = 0;
        int val=0, sum=0;

        Node(int _val): val(_val), sum(val), pri(rng()){}

        void pull(){
            sz = 1;
            sum = val;
            for(auto i:{l,r}){
                if(i){
                    sz += i->sz;
                    sum += i->sum;
                }
            }
        }

        void push(){
            if(rev){
                for(auto i:{l,r}){
                    if(i){
                        i->rev ^= 1;
                        swap(i->l, i->r);
                    }
                }
                rev = 0;
            }
        }
    };

    Node *root = nullptr;

    int size(Node *rt){
        return rt ? rt->sz : 0;
    }

    pair<Node*, Node*> split(Node *rt, int k){
        if(!rt) return {nullptr, nullptr};

        rt->push();

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

        a->push();
        b->push();

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

    void reverse(int l, int r){
        auto [ab, c] = split(root, r);
        auto [a,b] = split(ab, l-1);

        b->rev ^= 1;
        swap(b->l, b->r);

        root = merge(merge(a, b), c);
    }

    void append(int x){
        root = merge(root, new Node(x));
    }

    int query(int l, int r){
        auto [ab,c] = split(root, r);
        auto [a, b] = split(ab, l-1);

        int ans = b->sum;

        root = merge(merge(a, b), c);

        return ans;
    }

};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin>>n>>m;

    Treap trp;

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        trp.append(x);
    }

    while(m--){
        int ty;
        cin>>ty;
        if(ty == 1){
            int l, r;
            cin>>l>>r;
            trp.reverse(l, r);

        }
        else{
            int l, r;
            cin>>l>>r;
            cout << trp.query(l, r) << '\n';

        }
    }

}