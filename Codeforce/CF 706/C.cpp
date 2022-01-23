#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        int N; cin >> N;
        long double ans = 0;
        vector<long double> miner, dia;
        for(int i=0; i<N*2; ++i){
            int a, b; cin >> a >> b;
            if(a) dia.push_back(a*a);
            else miner.push_back(b*b);
        }
        sort(miner.begin(),miner.end());
        sort(dia.begin(), dia.end());
        for(int i=0; i<N; ++i){
            ans += sqrt(miner[i] + dia[i]);
        }
        cout << fixed;
        cout.precision(20);
        cout << ans << '\n';
    }    
    return 0;
}