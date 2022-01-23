#include<bits/stdc++.h>

using namespace std;

int psum[1025][1025];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    // for(int r=1; r<=N; ++r)        
    // for(int c=1; c<=N; ++c){
    //     int inp; cin >> inp;
    //     psum[r][c] = psum[r][c-1] + inp;
    // }
    // for(int i=0; i<M; ++i){
    //     int r1, c1, r2, c2, ans =0; cin >> r1 >> c1 >> r2 >> c2;
    //     for(int r=r1; r<=r2; ++r){
    //         ans += psum[r][c2] - psum[r][c1-1];
    //     }
    //     cout << ans << '\n';
    // }
    for(int r=1; r<=N; ++r)
    for(int c=1; c<=N; ++c){
        int inp; cin >> inp;
        psum[r][c] = psum[r-1][c] + psum[r][c-1] - psum[r-1][c-1] + inp;
    }
    for(int i=0; i<M; ++i){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        cout << psum[r2][c2] - psum[r2][c1-1] - psum[r1-1][c2] + psum[r1-1][c1-1] << '\n';
    }
    return 0;
}