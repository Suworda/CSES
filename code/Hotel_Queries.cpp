#include <bits/stdc++.h>
using namespace std;
#define lid id*2
#define rid id*2+1

int n,m;
int h[200005];
int seg[800005];

struct SegT{
    void pull(int id){
        seg[id] = max(seg[lid],seg[rid]);
    }

    void build(int l, int r, int id){
        if(l == r){
            seg[id] = h[l];
            return;
        }
        int m = (l+r)/2;
        build(l, m, lid);
        build(m+1, r, rid);
        pull(id);
    }

    void upd(int l, int r, int x, int id){
        if(l == r){
            cout<<l<<' ';
            seg[id] -= x;
            return;
        }

        int m = (l+r)/2;
        if(seg[lid] >= x) upd(l,m,x,lid);
        else upd(m+1,r,x,rid);
        pull(id);
    }

} segt;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>h[i];
    segt.build(1,n,1);
    
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        if(seg[1] < x){
            cout<<0<<' ';
            continue;
        }
        segt.upd(1,n,x,1);
    }

}