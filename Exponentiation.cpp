#include <iostream>
#include <algorithm>
using namespace std;

const int M=1000000007;

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        long long cur=1;
        if(b==0){
            cout<<1<<'\n';
            continue;
        }

        for(int i=__lg(b); i>=0; i--){
            cur*=cur;
            cur%=M;
            if((b>>i) & 1 == 1){
                cur*=a;
                cur%=M;
            }
        }
        cout<<cur<<'\n';
    }
}
