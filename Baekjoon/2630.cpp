#include<bits/stdc++.h>

using namespace std;
vector<vector<int> > table;

int chacker(const int rb, const int cb, const int n){
    assert(n!=0);
    int first = table[rb][cb];
    for(int r=rb; r<rb+n; ++r){
        for(int c=cb; c<cb+n; ++c){
            if(table[r][c] != first) return -1;
        }
    }
    return first;
}

void div(const int rb, const int cb, const int n, int &w, int &b){
    int res = chacker(rb, cb, n);
    int half = n/2;
    switch(res){
        case -1:
        div(rb, cb, half, w, b);
        div(rb, cb+half, half, w, b);
        div(rb+half, cb, half, w, b);
        div(rb+half, cb+half, half, w, b);    
        break;
        case 0:
        ++w;
        break;
        case 1:
        ++b;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, w, b; cin >> n; w = b = 0;
    for(int i=0; i<n; ++i){
        vector<int> vt(n);
        for(int j=0; j<n; ++j){
            int t; cin >> t;
            vt[j] = t;
        }
        table.push_back(vt);
    }
    div(0, 0, n, w, b);
    cout << w << '\n' << b << '\n';
    return 0;
}