#include<bits/stdc++.h>

using namespace std;

bool painted[32001];

void dp(int me, vector<vector<int> > &pointing){
    if(painted[me]) return;
    if(!pointing[me].empty()){
        for(int shooter : pointing[me]){
            dp(shooter, pointing);
        }
    }
    painted[me] = true;
    cout << me << ' ';
    return;    
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<vector<int> > pointing(N+1);
    for(int i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        pointing[b].push_back(a);
    }
    for(int i=1; i<=N; ++i){
        dp(i, pointing);
    }
    return 0;
}