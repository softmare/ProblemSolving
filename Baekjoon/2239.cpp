#include<bits/stdc++.h>

using namespace std;
int table[9][9];
bool sqr[9][10], col[9][10], row[9][10];

void on_off(const int y, const int x, const int num, bool able){
    row[y][num] = able;  
    col[x][num] = able;
    sqr[(x/3) + (y/3)*3][num] = able;
    return ;
}

bool check(const int y, const int x, const int num){
    if(!sqr[(x/3) + (y/3)*3][num]) return false;
    if(!col[x][num]) return false;
    if(!row[y][num]) return false;
    return true;
}

bool dp(const int sy){
    int y,x; bool completed = true;
    for(int r=sy; r<9; ++r){
        for(int c=0; c<9; ++c)
            if(!table[r][c]){y=r; x=c; completed = false; break;}
        if(!completed) break;
    }
    if(completed) return true;    
    for(int i=1; i<=9; ++i){
        if(!check(y, x, i)) continue;
        //cout << i << " is good. keep try" << endl;
        on_off(y,x,i,false);
        table[y][x] = i;
        int _y = y + (x+1)/9;        
        if(dp(_y)) { return true; }
        on_off(y,x,i,true);
        //cout << "i'm " << y << ' ' << x << " and "<< i << " is failed" << endl;
    }
    table[y][x] = 0;
    return false;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);    
    memset(sqr,1,sizeof(sqr));
    memset(row,1,sizeof(row));
    memset(col,1,sizeof(col));
    for(int r=0; r<9; ++r)
    for(int c=0; c<9; ++c){
        char t; cin >> t; t = t-'0';
        if(!t) continue;
        on_off(r,c,t,false);
        table[r][c] = t;
    }
    dp(0);
    for(int r=0; r<9; ++r){
        for(int c=0; c<9; ++c)
            cout << table[r][c];
        cout << '\n';
    }
    return 0;
}