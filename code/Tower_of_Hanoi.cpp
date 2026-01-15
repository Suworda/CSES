#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ans;
void move(int n, int s, int t){
    if(n == 1){
        ans.push_back({s,t});
        return;
    }
    move(n-1, s, 6-s-t);
    ans.push_back({s,t});
    move(n-1, 6-s-t, t);
}
int main(){
    int n;
    cin>>n;
    move(n, 1, 3);
    cout<<ans.size()<<'\n';
    for(auto [a,b]: ans){
        cout<<a<<' '<<b<<'\n';
    }
}