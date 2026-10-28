#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

struct Graph{
    int n;
    int mask;
    vector<int> ptr;

    Graph(int _n): n(_n), ptr(1<<(n-1)), mask((1<<(n-1))-1) {}

    string get_ans(){
        string ans;
        ans.reserve(1 << n);

        auto dfs = [&](auto &&dfs, int u) -> void {
            while(ptr[u] < 2){
                int bit = ptr[u]++;
                int v = ((u << 1) | bit) & mask;

                dfs(dfs,v);
                ans.push_back('0' + bit);
            }
        };

        dfs(dfs, 0);
        reverse(ans.begin(), ans.end());
        return string(n-1, '0') + ans;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    
    Graph g(n);
    cout << g.get_ans() << '\n';
}