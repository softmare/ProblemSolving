#include<bits/stdc++.h>

using namespace std;

void dfs(const int start, vector<vector<pair<int, int> > > &v, int &dot, int &longest){
    bool paint[100001];
    memset(paint, 0, sizeof(paint));
    longest = 0;
    queue<pair<int, int> > q;
    paint[start] = 1;
    q.push(pair<int, int>(start, 0));
    while(!q.empty()){        
        auto el = q.front();
        bool leaf = true;
        for( auto pr : v[el.first] ){
            if(paint[pr.first]) continue;
            leaf = false;
            q.push(pair<int,int>(pr.first, pr.second + el.second));
            paint[pr.first] = true;
        }
        if(leaf){
            if(longest < el.second){
                dot = el.first;
                longest = el.second;
            }
        }
        q.pop();
    }
    return;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, dot, ans; cin >> N;
    vector<vector<pair<int, int> > > v(N+1); // a 가 노드, b가 가중치
    for(int n=1; n<=N; ++n){
        int temp; cin>>temp;
        vector<pair<int, int> > vt;
        while(true){
            int a, b; cin >> a;
            if(a == -1) break;
            cin >> b;
            vt.push_back(pair<int, int>(a, b));
        }        
        v[temp] = vt;
    }    
    dfs(1, v, dot, ans);
    dfs(dot, v, N, ans);
    cout << ans << endl;
    return 0;
}