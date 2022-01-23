#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> v;
    for(int i=1; i<3000000;++i){
        string s = to_string(i);
        if(s.find("666") != string::npos)
            v.push_back(i);
    }
    int N; cin >> N;
    cout << v[N-1] << endl;
    return 0;
}