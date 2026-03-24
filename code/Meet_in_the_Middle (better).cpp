#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

int N,n,x;
int a[45];
vector<int> v1, v2;
ll ans = 0;

void get_ans(){
    int it1 = 0, it2 = 0;
    while(it1 < v1.size() && it2 < v2.size()){
        if(v1[it1] < v2[it2]) it1++;
        else if(v1[it1] > v2[it2]) it2++;
        else{
            int cnt = 0;
            while(it1 < v1.size() && v1[it1] == v2[it2]){
                it1++;
                cnt++;
            }
            while(it2 < v2.size() && v2[it2] == v1[it1-1]){
                it2++;
                ans += cnt;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>x;
    n = N/2;
    for(int i=0; i<N; i++){
        cin>>a[i];
    }

    for(int i=0; i<(1<<n); i++){
        int rst = 0;
        for(int j=0; j<n; j++){
            if((i >> j) & 1) rst += a[j];
        }
        v1.push_back(rst);
    }
    sort(v1.begin(), v1.end());

    for(int i=0; i<(1<<(N-n)); i++){
        int rst = 0;
        for(int j=0; j<N-n; j++){
            if((i >> j) & 1) rst += a[j+n];
        }
        v2.push_back(x-rst);
    }
    sort(v2.begin(), v2.end());

    get_ans();

    cout<<ans<<'\n';


}