#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    sort(s.begin(), s.end());

    vector<string> ans;
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout<<ans.size()<<'\n';
    for(auto &x: ans){
        cout<<x<<'\n';
    }
}
