#include<bits/stdc++.h>

using namespace std;

bool printed[1001], onPath[1001];
vector<int> ans;
vector<vector<int> > before(1001);

bool dp(const int me){
    if(onPath[me]) return false;
    if(printed[me]) return true;
    if(before[me].empty()){
        ans.push_back(me);
        printed[me] = true;
        return true;
    }
    onPath[me] = true;
    for(int from : before[me]){
        if(onPath[from]) return false;
        if(!dp(from)) return false;
    }
    ans.push_back(me);    
    printed[me] = true;
    onPath[me] = false;
    return true;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M; cin>> N >> M;
    for(int i=0;i<M;++i){
        int k, last; cin >> k;
        if(!k) continue;
        else cin >> last;
        for(int j=1; j<k; ++j){
            int me; cin >> me;
            before[me].push_back(last);
            last = me;
        }
    }
    bool isPossible = true;
    for(int i=1; i<=N; ++i){
        if(!dp(i)){
            isPossible = false;
            break;
        }
    }
    if(isPossible){
        for(int i=0; i<N; ++i){
            cout << ans[i] << '\n';
        }       
    }else{
        cout << 0 << '\n';
    }
    return 0;
}