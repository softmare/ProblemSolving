#include<bits/stdc++.h>

using namespace std;

int table[101][100001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, K, ans=0; cin >> N >> K;    
    for(int i=1; i<N+1; ++i){
        int w, v; cin >> w >> v;
        for(int k=K; k >=0; --k){
            if(w > k) table[i][k] = table[i-1][k];
            else{
                table[i][k] = max(table[i-1][k], table[i-1][k-w]+v);
            }
            ans = max(ans, table[i][k]);
        }
    }
    cout << ans << endl;
    return 0;
}