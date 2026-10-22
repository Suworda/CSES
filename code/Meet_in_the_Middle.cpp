#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[45];
ll ans;
vector<int> v[2];
int cnt[4000005];
// unordered_map<int,int> cnt;
int n,x;

void get_ans(){
    vector<int> d;
    for(int &y: v[0]) d.push_back(y);
    for(int &y: v[1]) d.push_back(x-y);
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());

    for(int &tg: v[0]){
        auto it = lower_bound(d.begin(), d.end(), tg);
        cnt[it - d.begin()]++;
    }
    
    for(int &tg: v[1]){
        if(x-tg >= 0){
            auto it = lower_bound(d.begin(), d.end(), x-tg);
            ans += cnt[it - d.begin()];
            // cout<<*it<<'\n';
        }

    }

}

void dfs_cnt(int ty, int idx, int ed, ll sum){
    if(sum > 1e9) return;
    if(idx == ed){
        v[ty].push_back(sum);
        return;
    }
    dfs_cnt(ty, idx+1, ed, sum);
    dfs_cnt(ty, idx+1, ed, sum+a[idx]);
}

// void dfs_ans(int idx, int ed, ll sum){
//     // cout<<sum<<'\n';
//     if(sum > 1e9) return;
//     if(idx == ed){
//         ans += cnt[x-sum];
//         return;
//     }
//     dfs_ans(idx+1, ed, sum);
//     dfs_ans(idx+1, ed, sum+a[idx]);
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    dfs_cnt(0, 0, n/2, 0);
    dfs_cnt(1, n/2, n, 0);
    get_ans();
    // dfs_ans(n/2, n, 0);

    cout<<ans<<'\n';

}