#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long



signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    for(int i=1;;i++){
        cout << i << " : \n";
        string cmd1 = "gen.exe > in.txt";
        system(cmd1.c_str());
        cout << "cmd1 ok\n";
        string cmd2 = "1.exe < in.txt > 1.txt";
        system(cmd2.c_str());
        cout << "cmd2 ok\n";
        string cmd3 = "2.exe < in.txt > 2.txt";
        system(cmd3.c_str());
        cout << "cmd3 ok\n";

        fstream a("1.txt");
        fstream b("2.txt");

        for(int j=1;;j++){
            string s;
            if(!getline(a, s)) break;
            string t;
            if(!getline(b, t)) break;

            if(s != t){
                cout << "WA on line : " << j << '\n'; 

                fstream WA_INPUT("in.txt");
                string x;
                cout << "WA_INPUT : \n";
                while(getline(WA_INPUT, x)){
                    cout << x << '\n';
                }

                cout << "AC : " << t << '\n';
                cout << "WA : " << s << '\n';
                return 0;
            }
            
        }
        


    }

}