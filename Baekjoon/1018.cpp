#include<bits/stdc++.h>

using namespace std;

int pans(const int y, const int x, vector<vector<char> > &table){
    int cnt = 0;
    for(int r=0; r<8; ++r)
        for(int c=0; c<8; ++c){
            char t = (r+c) % 2 ? 'W' : 'B';
            cnt += t == table[y+r][x+c] ? 1 : 0;
        }
    return min(cnt, 64-cnt);    
}

int main(){
    vector<vector<char> > table;
    int N, M, ans = 9999; cin >> N >> M;
    for(int r=0; r<N; ++r){
        vector<char> v;
        for(int c=0; c<M; ++c){
            char t; cin >> t;
            v.push_back(t);
        }
        table.push_back(v);
    }

    for(int r = 0; r<=N-8; ++r)
        for(int c = 0; c<=M-8; ++c){
            ans = min(ans, pans(r, c, table));
            //cout << "r : " << r << "  c: " << c << "  pan : " << pans(r, c, table) << endl;
        }
    cout << ans << endl;
    return 0;
}