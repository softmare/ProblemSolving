#include<bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        string s; cin >> s;
        if(s == "0") break;
        bool ans = true;
        string::iterator it1 = s.begin();
        string::reverse_iterator it2 = s.rbegin();
        for(; it1 !=s.end(); ++it1, ++it2){
            if(*it1 != *it2){
                ans = false;
                break;
            }
        }
        cout << (ans ? "yes" : "no") << endl;
    }
    return 0;
}