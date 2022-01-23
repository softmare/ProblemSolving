#include<bits/stdc++.h>

using namespace std;

bool is_prime(int num){
    if(num < 2) return false;
    bool yes_prime = true;
    int until = sqrt(num) + 1;
    for(int i=2; i < until; ++i){
        if(!(num%i)){ 
            yes_prime = false; break;
            }
    }
    return yes_prime;
}

bool is_palendrom(string s){
    bool yes_pal = true;
    for(int i=0, r=s.length()-1; i <= s.size()>>1; ++i, --r){
        if(s[i] != s[r]) {yes_pal = false; break;}
    }
    return yes_pal;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    while(!is_prime(N) || !is_palendrom(to_string(N))){ ++N;}
    cout << N << '\n';
    return 0;
}