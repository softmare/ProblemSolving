#include<bits/stdc++.h>

/*
천천히 품. 33분
*/

using namespace std;

int mem[10001];
int cost[10001];

int dp(int tgt, vector<vector<int> > &childs){    
    int &ret = mem[tgt];
    if(ret != -1) return ret;
    if(childs[tgt].empty()){
        ret = cost[tgt];        
        return ret;
    }
    for(int child : childs[tgt]){
        ret = max(ret, dp(child, childs)+cost[tgt]);        
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(mem,-1,sizeof(mem));
    int N; cin >> N;
    vector<vector<int> > childs(N+1);
    int ans = 0;
    for(int i=1; i<=N; ++i){
        int a, b; cin >> a >> b;
        cost[i] = a;
        //cout << 'a' << a << 'b' << b << endl;
        for(int j=0; j<b; ++j){
            int tm; cin >> tm;
            //cout << "tm : " << tm << endl;
            childs[tm].push_back(i);
        }        
    }    
    for(int i=1; i<=N; ++i){
        ans = max(ans, dp(i, childs));
    }
    cout << ans << endl;
    return 0;
}