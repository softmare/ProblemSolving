#include<bits/stdc++.h>

using namespace std;

bool paint[200001];
long long ans[200001];

struct pair_cmp{
    bool operator()(const pair<int,long long> a, const pair<int,long long> b) const {
        return a.second > b.second;
    }
};
 

void bfs(const int S, vector<map<int,long long> > &v, priority_queue<pair<int, long long>, vector<pair<int,long long> >, pair_cmp> &q){            
    memset(ans, -1, sizeof(ans));
    ans[S] = 0;
    q.push(pair<int, long long>(S, 0));
    while(!q.empty()){
        auto pr = q.top();
        if(!paint[pr.first]) {
            ans[pr.first] = pr.second;
            paint[pr.first] = true;
            for(auto mpr : v[pr.first]){
                if(paint[mpr.first]) continue;            
                q.push(pair<int, long long>(mpr.first, pr.second + mpr.second));                
            }
        }
        //cout << "i'm : " << pr.first << " and weight : " << pr.second << endl;
        q.pop();
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int V, E, S; cin >> V >> E >> S;
    vector<map<int,long long> > v(V+1);    
    for(int i=0; i<E; ++i){
        int a, b, c; cin >> a >> b >> c;
        if(v[a].find(b) != v[a].end() && v[a][b] < c){
            continue;
        }else{
            v[a][b] = c;
        }
    }
    priority_queue<pair<int, long long>, vector<pair<int,long long> >, pair_cmp> q;
    bfs(S, v, q);
    for(int i=1; i<=V; ++i){
        if(ans[i] == -1) cout << "INF" << '\n';
        else cout << ans[i] << '\n';
    }
    return 0;
}