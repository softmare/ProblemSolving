#include<bits/stdc++.h>

using namespace std;

int N, M, ans, map_o[50][50], k, map_[50][50];

void toggle(const int x){
    for(int y=0; y<M; y++){
        map_[y][x] ^= 1;
    }
}

int row_cnt(){
    int cnt = 0;
    for(int y=0; y<N; y++){
        bool row_on = true;
        for(int x=0; x<M; x++){
            if(map_[y][x]) continue;
            row_on = false;
            break;
        }
        if(row_on) cnt++;
    }
    return cnt;
}

int main(){
    cin.sync_with_stdio(false);
    cin >> N >> M;
    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            cin >> map_o[y][x];
        }
    }
    cin >> k;

    return 0;
}