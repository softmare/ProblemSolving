#include<bits/stdc++.h>

using namespace std;

int N, M;

typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
const int add[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool keep_go[5][4] = {{0,0,1,1},{0,0,1,1},{1,1,0,0},{1,1,0,0},{1,1,1,1}};

// 0 위로, 1 아래로, 2 오른쪽, 3 왼쪽

pii where(const pii &ball, const int &dir, const vvi &tb) {// 벽만 고려.
    
    pii ball_dst = ball; int &r = ball_dst.first, &c = ball_dst.second;
    while(!tb[r][c]){
        r += add[dir][0], c += add[dir][1];
    }
    r-=add[dir][0], c-=add[dir][1];
    return ball_dst;
}

bool hall_in(const pii &b_b, const pii &b_a, const pii &hall, const vvi &tb){
    const int r_st = min(b_b.first,b_a.first), r_dst = max(b_b.first, b_a.first);
    const int c_st = min(b_b.second,b_a.second), c_dst = max(b_b.second,b_a.second);
    for(int r=r_st; r<=r_dst; ++r)
    for(int c=c_st; c<=c_dst; ++c){
        if(r==hall.first && c==hall.second) return true;
    }
    return false;
}

void modify(const pii R_b, const pii B_b, pii &R_a, pii &B_a, const int dir, const vvi &tb){
    if(R_a != B_a) return;
    pii *winner, *losser; bool flag;
    switch(dir){
        case 0:
        flag = R_b.first < B_b.first;
        break;
        case 1:
        flag = R_b.first > B_b.first;
        break;
        case 2:
        flag = R_b.second > B_b.second;
        break;
        case 3:
        flag = R_b.second < B_b.second;
        break;
        default:
        assert(false);
    }
    if(flag){
        winner = &R_a; losser = &B_a;
    }else{
        winner = &B_a; losser = &R_a;
    }
    losser->first -= add[dir][0], losser->second -= add[dir][1];
    return ;
}

void just_push(pii &R, pii &B, const int dir, vvi &tb){
    pii R_b = R, B_b = B;
    R = where(R, dir, tb), B= where(B, dir, tb);
    modify(R_b, B_b, R, B, dir, tb);
    return ;
}

void show(vvi tb, pii R, pii B, pii H){
    tb[R.first][R.second] = 4, tb[B.first][B.second] = 7, tb[H.first][H.second] = 9;
    for(int r=0;r<N;++r){
        for(int c=0;c<M;++c) cout << tb[r][c];
        cout << '\n';
    }
    return ;
}

void dp(const pii R, const pii B, const pii &H, const int prev_dir, int cnt, int &ans, const vvi &tb){
    if(cnt == 10) return;
    ++cnt;
    for(int i=0; i<4; ++i){
        if(!keep_go[prev_dir][i]) continue;
        pii R_a=where(R,i,tb), B_a=where(B,i,tb);
        if(hall_in(B,B_a,H,tb)) continue;
        if(hall_in(R,R_a,H,tb)) {ans = min(ans, cnt); return;}
        modify(R,B,R_a,B_a,i,tb);
        dp(R_a,B_a,H,i,cnt,ans,tb);
    }
    return ;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    vvi tb(N); 
    pii R, B, H;
    int ans = 100;
    for(int r=0; r<N; ++r)
    for(int c=0; c<M; ++c){
        char tc; cin >> tc;
        if(tc == '#'){
            tb[r].push_back(1);
            continue;
        }else if(tc == 'R'){
            R.first=r; R.second=c;
        }else if(tc == 'B'){
            B.first=r; B.second=c;
        }else if(tc == 'O'){
            H.first=r; H.second=c;
        }
        tb[r].push_back(0);
    }
    // show(tb, R, B, H);
    // while(true){
    //     int t; cin >> t;
    //     just_push(R,B, t, tb);
    //     show(tb, R, B, H);
    // }
    dp(R,B,H,4,0,ans,tb);
    if(ans == 100) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}