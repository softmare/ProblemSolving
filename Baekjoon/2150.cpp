#include<bits/stdc++.h>

using namespace std;

void stack_dfs(const int me, const vector<vector<int> > &ori_edges, stack<int> &st, vector<bool> &painted){
    if(painted[me]) return;
    painted[me] = true;
    for(int childs : ori_edges[me]){
        stack_dfs(childs, ori_edges, st, painted);
    }
    st.push(me);
}

void travel(const int me, vector<vector<int> > &rev_edges, vector<bool> &painted, set<int> &iset){
    if(painted[me]) return ;
    iset.insert(me);
    painted[me] = true;
    for(int childs : rev_edges[me]){
        travel(childs, rev_edges, painted, iset);
    }
    return ;
}

bool cmp(const set<int> &a, const set<int> &b){
    return *a.begin() < *b.begin();
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    stack<int> st;
    vector<set<int> > anset;
    int V, E; cin >> V >> E;
    vector<vector<int> > ori_edges(V+1), rev_edges(V+1);
    vector<bool> painted(V+1, false);
    for(int i=0; i<E; ++i){
        int a,b; cin >> a >> b;
        ori_edges[a].push_back(b);
        rev_edges[b].push_back(a);
    }
    for(int i=1; i<=V; ++i){
        if(painted[i]) continue;
        stack_dfs(i, ori_edges, st, painted);
    }
    painted = vector<bool>(V+1, false);
    for(int i; st.size(); st.pop()){
        i = st.top();
        if(painted[i]) continue;
        set<int> tset;
        travel(i, rev_edges, painted, tset);
        anset.push_back(move(tset));
    }
    sort(anset.begin(), anset.end(), cmp);
    cout << anset.size() << '\n';
    for(const auto iset : anset){
        for(const auto ii : iset){
            cout << ii << ' ';
        }cout << -1 << '\n';
    }    
    return 0;
}