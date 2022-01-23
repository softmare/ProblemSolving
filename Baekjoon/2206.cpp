#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
struct task{
    int cnt, y, x;
    int trou;
    task(int cnt, int y, int x, int trou) : cnt(cnt), y(y), x(x), trou(trou)  {}
};

int record[1001][1001][2];
int table[1001][1001];
int N, M;

bool oor(const int y, const int x){
    return y<1 || x<1 || y>N || x>M;
}

void bfs(queue<task> &q){    
    while(!q.empty()){
        task t = q.front(); q.pop();
        //cout << t.y << ' ' << t.x << endl;
        if(oor(t.y, t.x)) continue;
        if(table[t.y][t.x] == 1){
            ++t.trou;
            assert(t.trou < 3);
        }    
        if(t.trou >= 2) continue;
        int &prec = record[t.y][t.x][t.trou];
        if(prec <= t.cnt) continue;
        prec = t.cnt;    
        for(int i=0; i<4; ++i){
            task nq(t.cnt+1,t.y+dir[i][0],t.x+dir[i][1],t.trou);        
            q.push(nq);
        }
    }
    return;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    queue<task> q;
    cin >> N >> M;
    int ans;
    for(int r=1; r<N+1; ++r)
    for(int c=1; c<M+1; ++c){
        char tc; cin >> tc;
        table[r][c] = tc - '0';
        record[r][c][0] = record[r][c][1] = INF;
    }
    q.push(task(1,1,1,0));
    bfs(q);
    ans = min(record[N][M][0],record[N][M][1]);
    ans = ans != INF ? ans : -1;
    cout << ans << endl;

    return 0;
}