#include<bits/stdc++.h>



using namespace std;

int best[1001];
int cost[1001];

int dp(int me, vector<vector<int> > &shooters){
    int &ret = best[me];
    if(ret != -1) return ret;
    if(shooters[me].empty()){
        ret = cost[me];
        return ret;
    }       
    for(int shooter : shooters[me]){
        ret = max(ret, dp(shooter, shooters) + cost[me]);
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, N, K, W; cin >> T;
    for(int t=0; t<T; ++t){
        cin >> N >> K;
        vector<vector<int> > shooters(N+1);    
        memset(best,-1,sizeof(best));
        for(int i=1; i<=N; ++i){
            cin >> cost[i];
        }
        for(int i=0; i<K; ++i){
            int a, b; cin >> a >> b;
            shooters[b].push_back(a);
        }
        cin >> W;    
        cout << dp(W, shooters) << endl;
    }

    return 0;
}