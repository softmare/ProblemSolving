#include<bits/stdc++.h>

using namespace std;

set<string> s1, s2;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);    
    int n, m; cin >> n >> m;
    for(int i=0; i<n; ++i){
        string s; cin >> s;
        s1.insert(s);
    }
    for(int i=0; i<m; ++i){
        string s; cin >> s;
        if(s1.find(s) != s1.end()) s2.insert(s);
    }
    cout << s2.size() << endl;
    for(auto it = s2.begin(); it != s2.end(); ++it){
        cout << *it << '\n';
    }
    return 0;
}