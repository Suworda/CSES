#include <bits/stdc++.h>
using namespace std;
#define Grid string

unordered_set<Grid> vis;

int p1[]={1,2,-1,4,5,-1,7,8,-1};
int p2[]={3,4,5,6,7,8,-1,-1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vis.reserve(400005);
    
    Grid t;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            char c;
            cin>>c;
            t+=c;
        }
    }

    Grid s = "123456789";

    queue<pair<Grid,int>> q;
    q.push({s,0});
    vis.insert(s);

    while(q.size()){
        auto [x,cnt] = q.front();
        q.pop();

        if(x == t){
            cout<<cnt<<'\n';
            return 0;
        }

        for(int i=0; i<9; i++){
            if(p1[i] != -1){
                swap(x[i], x[p1[i]]);
                if(!vis.count(x)){
                    q.push({x,cnt+1});
                    vis.insert(x);
                }
                swap(x[i], x[p1[i]]);
            }

            if(p2[i] != -1){
                swap(x[i], x[p2[i]]);
                if(!vis.count(x)){
                    q.push({x,cnt+1});
                    vis.insert(x);
                }
                swap(x[i], x[p2[i]]);
            }
        }
    }

}