#include<bits/stdc++.h>

using namespace std;

struct cmp;

typedef pair<int,int> pii;
typedef priority_queue<pii, vector<pii>, cmp> ppq;
int cost[16][16];
const int INF = 987654321;
int N, full, ans= INF;

struct cmp{
    bool operator()(const pii a, const pii b) const {
        return a.second > b.second;
    }
};

int get_num(int id){
    return id>>16;
}

int renew_id(int num, int id){
    return (num<<16) | (((1<<16)-1) & (id | (1<<num)));
}

bool isComplete(int id){
    return (id & full) == full;
}

void p_hist(int id){
    for(int i=1; i<(1<<N); i<<=1){
        cout << (id&i ? "O" :  "X");
    }cout << '\n';
    return;
}

int mem[1<<20];

void dfs(ppq &flow){
    while(!flow.empty()){
        auto pr = flow.top(); flow.pop();
        int from = get_num(pr.first);
        //cout << "im on : " << from << " and weight is : " << pr.second << endl;
        //p_hist(pr.first);
        if(mem[pr.first] != -1 || pr.second >= INF){ //이미 다른 flow가 도달했던 경우
            continue; //해당 flow를 끝낸다.
        }
        if(isComplete(pr.first)){ // 마지막 from to 0만 남긴경우.            
            ans = min(ans, pr.second + cost[from][0]);
            //cout << "renew is : " <<  pr.second + cost[from][0] << " and ans is " << ans << endl;
        }
        mem[pr.first] = pr.second; // mem을 갱신.
        for(int num = 1; num < N; ++num){
            if(pr.first & (1<<num)) continue; // 가본적 있는 노드는 패스.
            flow.push({renew_id(num ,pr.first), pr.second + cost[from][num]}); //안가본 곳을 플로우에 추가.
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);    
    ppq flow;
    cin >> N;
    full = (1<<N)-1;
    memset(mem,-1, sizeof(mem));
    for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j){
        cin >> cost[i][j];
        cost[i][j] = cost[i][j] ? cost[i][j] : INF;
    }
    flow.push({renew_id(0, 1),0});    
    dfs(flow);    
    cout << ans << endl;
    return 0;
}

/*
dfs 응용으로 시도해봅시다.
*/