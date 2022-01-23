#include<bits/stdc++.h>

using namespace std;

int edges[101][101];
const int INF = 987654321;

void floid(const int N){
    for(int i=1; i<N+1; ++i)
    for(int j=1; j<N+1; ++j)
    for(int k=1; k<N+1; ++k){
        edges[i][j] = min(edges[i][k] + edges[k][j], edges[i][j]);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, E; cin >> N >> E;
    for(int i=0; i<101*101; ++i) edges[0][i] = INF;
    for(int i=0; i<101; ++i) edges[i][i] = 0;
    for(int i=0; i<E; ++i){
        int a, b, c; cin >> a >> b >> c;                
        edges[a][b] = min(edges[a][b], c);
    }
    for(int i=0; i<4; ++i) floid(N);
    for(int i=1; i<N+1; ++i){
       for(int j=1; j<N+1; ++j){
           cout << (edges[i][j] == INF ? 0 : edges[i][j]) << ' ';
       }cout << '\n';
    }
    return 0;
}