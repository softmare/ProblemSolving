#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<long long> > vvl;

int N, S, E, T;
const int MOD = 1000003;

void pr(vvl &table){
    for(int r=0; r<table.size(); ++r){
        for(int c=0; c<table.size(); ++c){
            cout << table[r][c] << ' ';
        }cout << '\n';
    }
    return ;
}

vvl operator*(vvl &a, vvl &b){
    vvl res(a.size(), vector<long long>(a.size()));
    for(int r=0; r<a.size(); ++r)
    for(int c=0; c<a.size(); ++c)
    for(int i=0; i<a.size(); ++i){
        res[r][c] += a[r][i] * b[i][c];
        res[r][c] %= MOD;
    }
    return res;
}



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> S >> E >> T;
    S = (S-1)*5, E = (E-1)*5;
    vvl table(5*N); for(int r=0; r<5*N; ++r) {table[r].assign(5*N, 0);}
    for(int i=1; i<N*5; ++i) if(i%5) table[i][i-1] = 1;
    for(int r=0; r<N; ++r){
        string s; cin >> s;
        for(int c=0; c<N; ++c){
            int t = s[c]-'0';
            if(t){
                table[r*5][c*5+t-1] = 1;                
            }
        }
    }    
    vvl ans(N*5, vector<long long>(N*5)); for(int i=0; i<5*N; ++i){ans[i][i] = 1;}
    while(T){
        if(T%2){ans = ans*table;}
        T/=2;
        table = table*table;
    }
    cout << ans[S][E] << '\n';
    return 0;
}