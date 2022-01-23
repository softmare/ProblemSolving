#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    while(s[0] != '*'){
        bool yes_surp= true;
        for(int d=1; d<s.size()-1; ++d){
            set<string> se;
            for(int i=0; i+d < s.size(); ++i){
                string ts = {s[i],s[i+d]};
                if(se.find(ts) == se.end()) se.insert(ts);
                else {yes_surp = false; break;}
            }
            if(!yes_surp) break;
        }
        cout << s << " is " << (yes_surp ? "" : "NOT ") << "surprising.\n";
        cin >> s;
    }    
    return 0;
}