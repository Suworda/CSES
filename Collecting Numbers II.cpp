#include <iostream>
#include <vector>
using namespace std;

int ans=1;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int x[n+2];
    vector<int> v(n+2);
    v[0]=0;
    v[n+1]=2e9;
    for(int i=1; i<=n; i++){
        cin>>x[i];
        v[x[i]]=i;
    }

    for(int i=2; i<=n; i++){
        ans+=(v[i-1]>v[i]);
    }

    while(m--){
        int a,b;
        cin>>a>>b;
        ans-=(v[x[a]-1]>v[x[a]]);
        ans-=(v[x[b]-1]>v[x[b]]);

        if(x[a]!=x[b]-1){
            ans-=(v[x[a]]>v[x[a]+1]);
        }
        if(x[b]!=x[a]-1){
            ans-=(v[x[b]]>v[x[b]+1]);
        }

        swap(v[x[a]],v[x[b]]);
        swap(x[a],x[b]);

        ans+=(v[x[a]-1]>v[x[a]]);
        ans+=(v[x[b]-1]>v[x[b]]);

        if(x[a]!=x[b]-1){
            ans+=(v[x[a]]>v[x[a]+1]);
        }
        if(x[b]!=x[a]-1){
            ans+=(v[x[b]]>v[x[b]+1]);
        }

        cout<<ans<<'\n';

    }
}
