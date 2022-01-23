#include<bits/stdc++.h>

using namespace std;

const int mult[4][2] = {{0,0}, {0, -1}, {-1, 0}, {-1, -1}};

int main(){
    int N, r, c, ans = 0;
    cin >> N >> r >> c;
    while(N){
        //cout << "r : " << r << " c : " << c << endl;
        int quart = 0, div = (1 << (N-1));
        if(div <= c) quart += 1;
        if(div <= r) quart += 2;
        ans += div * div * quart;
        r += mult[quart][0] * div;
        c += mult[quart][1] * div;
        --N;
        //cout << "ans : " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}