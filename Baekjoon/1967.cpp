#include<bits/stdc++.h>

using namespace std;


bool have_way(const int here, vector<bool> &passed, vector<vector<pair<int, int> > > &edges){
    bool have = false;
    for(auto pr : edges[here]){
        if(passed[pr.first]) continue;
        have = true;
        break;
    }
    return have;
}

void dfs(int here, int sum, int &longest, int &tgn, vector<vector<pair<int, int> > > &edges, vector<bool> &passed){        
    if(!have_way(here, passed, edges)){
        if(sum >= longest){
            longest = sum;
            tgn = here;
        }
        return ;
    }
    passed[here] = true;
    for(auto pr : edges[here]){
        if(passed[pr.first]) continue;
        dfs(pr.first, sum+pr.second, longest, tgn, edges, passed);
    }
    passed[here] = false;
    return ;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    vector<vector<pair<int, int> > > edges(N+1);   
    vector<bool> passed(N+1, false);
    for(int i=0; i<N-1; ++i){
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    int tgn, longest=0;
    dfs(1, 0, longest, tgn, edges, passed);
    longest = 0;
    dfs(tgn, 0, longest, tgn, edges, passed);
    cout << longest << endl;
    return 0;
}