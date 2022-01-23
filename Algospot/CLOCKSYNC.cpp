#include<bits/stdc++.h>

using namespace std;

const int CLOCKS = 16, SWITCHS = 10, INF = 9999;

vector<int> clocks(16);
const char sw[10][17] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

bool isOrdered(){
    bool ordered = true;
    for(int c=0; c<CLOCKS; ++c){
        if(clocks[c] != 12) ordered = false;
    }
    return ordered;
}

void push(int si){    
    for(int c=0; c<CLOCKS; ++c){
        if(sw[si][c] == 'x'){
            clocks[c] += 3;
            if(clocks[c] == 15) clocks[c] = 3;
        }           
    }
    return ;
}

int dp(int si){    
    if(si == SWITCHS) return isOrdered() ? 0 : INF;
    int ret = INF;
    for(int cnt = 0; cnt < 4; ++cnt){
        ret = min(ret, cnt + dp(si+1));
        push(si);
    }
    return ret;
}


int main(){
    int T; cin >> T;
    for(int t=0; t<T; t++){
        for(int i=0; i< 16; i++){
            cin >> clocks[i];
        }        
        int ret = dp(0);
        cout << (ret == INF ? -1 : ret) << endl;
    }
    return 0;
}