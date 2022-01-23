#include<bits/stdc++.h>

using namespace std;

bool available(string &s, const int k){
    int zcnt = 0;
    for(auto it=s.begin(); it!=s.end(); ++it){
        zcnt += *it == '0' ? 1 : 0;
    }
    if(zcnt % 2 == k % 2 && zcnt <= k) return true;
    return false;
}

map<string, int> m;
string a[50];


int main(){
    int N, M, K, ans = 0; cin >> N >> M;
    for(int n=0; n<N; ++n){        
        cin >> a[n];
    }cin >> K;
    for(int n=0; n<N; ++n){
        string &s = a[n];        
        if(available(s, K)){            
            if(m.find(s)==m.end()){
                m[s] = 1;
            }else{
                m[s] += 1;
            }
        }        
    }
    for(auto it=m.begin(); it!=m.end(); ++it){
        ans = max(ans, it->second);        
    }
    cout << ans << endl;
    return 0;
}