#include<bits/stdc++.h>

using namespace std;

int gen_cnt(vector<int> &lans, const int &cut){
    int cnt = 0;
    for(int i : lans){ cnt += i/cut; }
    return cnt;
}

void search(const int lo, const int hi, const int &req, vector<int> &lans, int &ans){
    if(lo > hi || lo < 0) return;
    //cout << "lo : " << lo << " hi : " << hi << '\n';
    int mid = (lo+hi)/2;
    if(gen_cnt(lans, mid) >= req){
        ans = max(ans, mid);
        search(mid+1, hi, req, lans, ans);
    }else{
        search(lo, mid-1, req, lans, ans);
    }
    return ;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int K, N, ans=0; cin >> K >> N;
    vector<int> lans(K);
    for(int i=0; i<K; ++i){cin >> lans[i];}
    search(1, INT32_MAX-1, N, lans, ans);
    if(gen_cnt(lans, INT32_MAX) >= N ) ans = INT32_MAX;
    cout << ans << '\n';
    return 0;
}