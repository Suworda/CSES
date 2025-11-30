#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dr[]={1,1,-1,-1};
int dc[]={1,-1,1,-1};
int nr, nc;

string s[8];

bool in(int r, int c){
    return r>=0 && r<8 && c>=0 && c<8;
}

bool ok(vector<int> &p){

    //O(n^2)
//    bool apr[8][8]={};
//    for(int i=0; i<8; i++){
//        if(s[i][p[i]]=='*') return false;
//        //cout<<i<<' '<<p[i]<<'\n';
//        apr[i][p[i]]=true;
//    }
//
//    for(int i=0; i<8; i++){
//        for(int j=1; j<=8; j++){
//            for(int k=0; k<4; k++){
//                nr=i+dr[k]*j;
//                nc=p[i]+dc[k]*j;
//                if(in(nr,nc) && apr[nr][nc]) return false;
//            }
//        }
//    }

    bool apr[2][17]={};
    for(int i=0; i<8; i++){
        if(s[i][p[i]]=='*' || apr[0][i+p[i]] || apr[1][i-p[i]+8]) return false;

        apr[0][i+p[i]]=true;
        apr[1][i-p[i]+8]=true;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> p(8);
    for(int i=0; i<8; i++){
        cin>>s[i];
        p[i]=i;
    }

    int ans=0;
    do{
        ans+=(ok(p));
    }while(next_permutation(p.begin(), p.end()));

    cout<<ans<<'\n';
}
