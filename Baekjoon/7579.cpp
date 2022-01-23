#include<bits/stdc++.h>

using namespace std;

int table[101][10001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<int> mems(N+1), costs(N+1);
    for(int i=1; i<=N; ++i){        
        cin >> mems[i];
    }
    for(int i=1; i<=N; ++i){        
        cin >> costs[i];
    }
    for(int i=1; i<=N; ++i)
    for(int c=0; c<=10000; ++c){
        if(c < costs[i]) table[i][c] = table[i-1][c];
        else{
            table[i][c] = max(table[i-1][c - costs[i]] + mems[i], table[i-1][c]);
        }
    }
    int ans = -1;
    for(int c=0; c<=10000; ++c){        
        for(int i=1; i<=N; ++i){
            if(table[i][c] >=M){
                ans = c;
                break;
            }
        }
        if(ans != -1) break;
    }
    cout << ans << endl;
    return 0;
}