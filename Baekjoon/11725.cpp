#include<bits/stdc++.h>

using namespace std;

bool painted[100001];

void trav(int from, int me, vector<vector<int> > &edges, vector<int> &parents){
    painted[me] = true;
    parents[me] = from;    
    for(auto near : edges[me]){
        if(painted[near]) {            
            continue;
        } 
        trav(me, near, edges, parents);
    }    
    painted[me] = false;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);    
    int N; cin >> N;
    vector<vector<int> > edges(N+1);
    vector<int> parents(N+1);
    for(int n=0; n<N-1; ++n){
        int a,b; cin>> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    trav(0, 1, edges, parents);
    for(int i=2; i<=N; ++i){
        cout << parents[i] << '\n';
    }
    return 0;
}