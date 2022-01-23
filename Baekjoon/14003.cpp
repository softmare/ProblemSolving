#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> inp, C, seq, ans;
    const int LOWEST = -1000000001;
    int N, cnt; cin >> N;
    for(int n=0; n<N; ++n){
        int t; cin>>t; inp.push_back(t);        
    }
    C.push_back(LOWEST);
    for(int i=0; i<N; ++i){
        if(C.back() < inp[i]){
            seq.push_back(C.size());
            C.push_back(inp[i]);
        }else{
            auto it = lower_bound(C.begin(), C.end(), inp[i]);
            *it = inp[i];
            seq.push_back(it-C.begin());
        }
    }
    cnt = C.size()-1;
    cout << cnt << '\n';
    for(int i=seq.size()-1; i>=0; --i){
        if(seq[i] == cnt){
            ans.push_back(i);
            --cnt;
        }
    }
    for(auto rit = ans.rbegin(); rit!= ans.rend(); ++rit){
        cout << inp[*rit] << ' ';
    }cout << '\n';
    return 0;
}