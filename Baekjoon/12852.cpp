#include<bits/stdc++.h>

using namespace std;

int mem[1000001];
int fromOf[1000001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    mem[0] = -1;
    for(int i=1; i<=N; ++i){
        mem[i] = mem[i-1] + 1;
        fromOf[i] = i-1;
        if(!(i%2) && mem[i/2]+1 < mem[i]){
            mem[i] = mem[i/2] +1;
            fromOf[i] = i/2;
        }
        if(!(i%3) && mem[i/3]+1 < mem[i]){
            mem[i] = mem[i/3] +1;
            fromOf[i] = i/3;
        }
    }    
    cout << mem[N] << '\n';
    while(N){
        cout << N << ' ';
        N = fromOf[N];
    }
    return 0;
}