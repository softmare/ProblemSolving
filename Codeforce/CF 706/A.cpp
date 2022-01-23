#include<bits/stdc++.h>

using namespace std;

int main(){
    // cin.tie(NULL);
    
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        int a, b; cin >> a >> b;
        string s, s1, s2; cin >> s;
        bool yes = true;
        s1 = s.substr(0,b);
        if(2*b+2 >= a) yes = false;
        else{
            for(int i=2*b+2;i>=b+2;--i){
                s2+=s[i];
            }
        }
        cout << s1 << ' ' << s2 << endl;

        if( s1 != s2) yes = false;
        cout << (yes? "YES" : "NO") << '\n';
    }
    return 0;
}