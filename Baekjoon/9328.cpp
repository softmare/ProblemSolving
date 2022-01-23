#include<bits/stdc++.h>

using namespace std;

/* 순서
0. TC 카운트를 받는다. 카운트만큼 아래를 반복.
0-1. 전역변수에 대한 초기화. (got_keys 키 모두 false). init()
1. r, c 를 입력받는다. 그 크기만큼 맵을 입력받는다. vvc
2. 키의 string을 받고 안에 있는 문자에 해당하는 key들을 true로 전환한다. 0인 경우 키를 받지 않는다.
정답찾기 시퀀스. 다음을 반복한다.
3-1. 딜리트 도어 시퀀스
3-2. find spot 시퀀스
3-3. run_around시퀀스. dp로 발견한 키를 true로 바꾸고, 빈공간으로 바꾸고, $는 카운트를 늘리고 빈공간으로 바꾼다.
3-4. 새로 발견한 키가 있으면 3-1로 돌아간다.
4. 발견한 문서수를 출력한다. 테스트케이스가 끝나지 않았으면 다시 위로.

*/


typedef vector<vector<char> > vvc;

bool got_keys[26];

void delete_door(vvc &table){
    int R, C; R = table.size(); C = table[0].size();
    for(int r=0; r<R; ++r)
    for(int c=0; c<C; ++c){
        char &A = table[r][c];
        if(isalpha(A) == 1 && got_keys[A-'A']) A = '.';
    }
    return;
}

void init(){
    memset(got_keys, false, sizeof(got_keys));
    return ;
}

bool is_spot(const int y, const int x, vvc &table){
    return table[y][x] == '.' || table[y][x] == '$' || isalpha(table[y][x]) == 2;
}

vector<pair<int,int> > find_spot(vvc &table){
    int R, C; R = table.size(); C = table[0].size();
    vector<pair<int, int> > spots;
    for(int r=0; r<R; ++r){
        if(is_spot(r,0,table)) spots.push_back({r,0});
        if(is_spot(r,C-1,table)) spots.push_back({r,C-1});
    }
    for(int c=0; c<C; ++c){
        if(is_spot(0,c,table)) spots.push_back({0,c});
        if(is_spot(R-1,c,table)) spots.push_back({R-1,c});
    }
    return spots;
}

void run_around(vvc &table, const vector<pair<int,int> > &spots, bool &key_added, int &doc_cnt){
    vvc t_copy = table;
    const int four_ways[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    queue<pair<int, int> > que;
    for(int i=0; i<spots.size(); ++i){
        que.push(spots[i]);
    }
    while(!que.empty()){
        const int y = que.front().first, x = que.front().second; que.pop();                
        //cout << "i arrived y: " << y << " x: " << x << " and I'm " << table[y][x] << endl;
        if(y < 0 || x < 0 || y == table.size() || x == table[0].size() || t_copy[y][x] == '*' || isalpha(table[y][x]) == 1) { continue; }
        if(isalpha(table[y][x])==2) {got_keys[table[y][x]-'a'] = true; key_added = true;}
        if(table[y][x] == '$') ++doc_cnt;
        t_copy[y][x] = '*';
        table[y][x] = '.';
        for(int i=0; i<4; ++i){
            que.push({y+four_ways[i][0],x+four_ways[i][1]});
        }        
    }
    return ;
}


int main(){
    //cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        init();
        int R, C; cin >> R >> C;
        vvc table(R);
        string start_keys;
        for(int r=0; r<R; ++r)
            for(int c=0; c<C; ++c){
                char tc; cin >> tc;
                table[r].push_back(tc);
            }       
        cin >> start_keys;
        if(start_keys[0] != '0'){
            for(int i=0; i<start_keys.size(); ++i) got_keys[start_keys[i]-'a'] = true;
        }
        int ans = 0;
        bool key_added;
        do{
            key_added = false;
            delete_door(table);
            run_around(table, find_spot(table), key_added, ans);
        }while(key_added);
        cout << ans << endl;
    }
    return 0;
}