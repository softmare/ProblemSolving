#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool painted[100001];

struct cmp{
    bool operator()(const pii a, const pii b) const{
        return a.second > b.second;
    }
};

void work(priority_queue<pii ,vector<pii>, cmp> &lefts, vector<vector<pii> > &edges, int &sum){
    while(!lefts.empty()){
        auto pr = lefts.top(); lefts.pop();
        if(painted[pr.first]) continue;
        painted[pr.first] = true;
        sum += pr.second;
        for(auto epr : edges[pr.first]){
            lefts.push({epr.first, epr.second});
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    priority_queue<pii ,vector<pii>, cmp> lefts;
    int V, E, ans = 0; cin >> V >> E;
    vector<vector<pii> > edges(V+1);
    for(int i=0; i<E; ++i){
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    painted[1] = true;
    for(auto pr : edges[1]){
        lefts.push(pr);
    }
    work(lefts, edges, ans);
    cout << ans << endl;
    return 0;
}