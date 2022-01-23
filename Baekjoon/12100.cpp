#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > vvi;

int N;

void merge(vvi &tb, const int dir){
    switch(dir){
        case 0: //up
        for(int c=0; c<N; ++c){
            int last(0), _r;
            for(int r=0; r<N; ++r){                
                if(!tb[r][c]) continue;
                else if(tb[r][c] != last){
                    last = tb[r][c];
                    _r = r;
                }else{
                    last = 0;
                    tb[_r][c] <<=1;
                    tb[r][c] = 0;
                }
            }
        }
        break;
        case 1:
        for(int c=0; c<N; ++c){
            int last(0), _r;
            for(int r=N-1; r>=0; --r){                
                if(!tb[r][c]) continue;
                else if(tb[r][c] != last){
                    last = tb[r][c];
                    _r = r;
                }else{
                    last = 0;
                    tb[_r][c] <<=1;
                    tb[r][c] = 0;
                }
            }
        }
        break;
        case 2:
        for(int r=0; r<N; ++r){
            int last(0), _c;
            for(int c=N-1; c>=0; --c){                
                if(!tb[r][c]) continue;
                else if(tb[r][c] != last){
                    last = tb[r][c];
                    _c = c;
                }else{
                    last = 0;
                    tb[r][_c] <<=1;
                    tb[r][c] = 0;
                }
            }
        }
        break;
        case 3:
        for(int r=0; r<N; ++r){
            int last(0), _c;
            for(int c=0; c<N; ++c){                
                if(!tb[r][c]) continue;
                else if(tb[r][c] != last){
                    last = tb[r][c];
                    _c = c;
                }else{
                    last = 0;
                    tb[r][_c] <<=1;
                    tb[r][c] = 0;
                }
            }
        }
        break;
        default:
        assert(false);
    }
    return;
}

void push(vvi &tb, const int dir){
    switch(dir){
        case 0:
        for(int c=0; c<N; ++c){
            int _r(0);
            for(int r=0; r<N; ++r){
                if(tb[r][c]){
                    if(_r==r) ++_r;
                    else{
                        tb[_r++][c] = tb[r][c];
                        tb[r][c] = 0;
                    }
                }
            }
        }
        break;
        case 1:
        for(int c=0; c<N; ++c){
            int _r(N-1);
            for(int r=N-1; r>=0; --r){
                if(tb[r][c]){
                    if(_r==r) --_r;
                    else{
                        tb[_r--][c] = tb[r][c];
                        tb[r][c] = 0;
                    }
                }
            }
        }
        break;
        case 2:
        for(int r=0; r<N; ++r){
            int _c(N-1);
            for(int c=N-1; c>=0; --c){
                if(tb[r][c]){
                    if(_c==c) --_c;
                    else{
                        tb[r][_c--] = tb[r][c];
                        tb[r][c] = 0;
                    }
                }
            }
        }
        break;
        case 3:
        for(int r=0; r<N; ++r){
            int _c(0);
            for(int c=0; c<N; ++c){
                if(tb[r][c]){
                    if(_c==c) ++_c;
                    else{
                        tb[r][_c++] = tb[r][c];
                        tb[r][c] = 0;
                    }
                }
            }
        }
        break;
        default:
        assert(false);
    }
    return ;
}

void show(vvi &tb){
    for(int r=0;r<N;++r){
        for(int c=0; c<N;++c) cout << tb[r][c];
        cout << '\n';        
    }
    return;
}

void dp(const int move_cnt, int &ans, vvi &tb){
    if(move_cnt==5){
        for(int r=0; r<N;++r)
        for(int c=0; c<N;++c)
        ans = max(ans, tb[r][c]);
        return;
    }
    for(int i=0; i<4; ++i){
        vvi _tb = tb;
        merge(_tb,i);
        push(_tb,i);
        dp(move_cnt+1, ans, _tb);
    }
    return ;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int ans = 0;
    cin >> N;
    vvi tb;
    for(int i=0; i<N; ++i){
        tb.push_back(vector<int>(N));
        for(int j=0; j<N; ++j){
            cin >> tb[i][j];
        }        
    }
    dp(0, ans, tb);
    cout << ans << '\n';
    return 0;
}