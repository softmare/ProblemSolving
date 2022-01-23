#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);    
    int ans = 0;
    for(int n=0; n<5; ++n){
        int t; cin >> t;
        ans += t*t;
    }
    cout << ans%10 << endl;
    return 0;
}