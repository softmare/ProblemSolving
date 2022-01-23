#include<bits/stdc++.h>

using namespace std;

int dp[100001];
bool painted[100001];
const int M = 100000;
struct cmp{
    bool operator()(const pair<int, int> a, const pair<int, int> b) const{
        return a.second > b.second;
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof(dp));
    int N, K; cin >> N >> K;
    int cnt = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, cmp > pq;
    pq.push({N, 0});    
    painted[N] = true;
    while(!pq.empty()){
        auto pr = pq.top(); pq.pop();
        int f = pr.first, w = pr.second;
        painted[f] = true;
        //cout << "f : " << f << " w : " << w << endl;                
        dp[f] = w;        
        if(!painted[f-1] && f-1 >= 0)
            pq.push({f-1,w+1});
        if(!painted[f+1] && f+1 <= M)
            pq.push({f+1,w+1});
        if(!painted[f*2] && f*2 <= M)
            pq.push({f*2,w});        
        if(painted[K]) break;
        cnt = max(cnt, (int)pq.size());
    }
    cout << dp[K] << endl;    
    return 0;
}