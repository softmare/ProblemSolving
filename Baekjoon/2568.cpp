#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<pair<int, int> > AB;
    vector<int> C, seq, ans;
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        int a, b; cin >> a >> b;
        AB.push_back({a,b});
    }
    C.push_back(0);
    sort(AB.begin(),AB.end());
    for(auto it=AB.begin(); it!=AB.end(); ++it){
        if(C.back() < it->second){
            seq.push_back(C.size());
            C.push_back(it->second);
        }else{
            auto renew = lower_bound(C.begin(),C.end(), it->second);
            *renew = it->second;
            seq.push_back(renew-C.begin());
        }
    }
    int an = C.size()-1;
    cout << N - an << '\n';
    for(int i=N-1; i>=0;--i){
        if(seq[i] == an) --an;
        else ans.push_back(i);
    }
    for(auto it=ans.rbegin(); it!=ans.rend(); ++it){
        cout << AB[*it].first << '\n';
    }
    return 0;
}