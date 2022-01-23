#include<bits/stdc++.h>

using namespace std;

bool checked[100001];
int cnt[100001];

void check(const int init, vector<int> &arr, vector<bool> &not_team, vector<bool> &overed){
    queue<int> que;
    que.push(init);    
    set<int> traveled;
    while(!que.empty()){
        const int me = que.front(); que.pop();
        if(cnt[me] > 1 || overed[me]) continue;
        ++cnt[me];
        traveled.insert(me);
        que.push(arr[me]);
    }
    for(int i : traveled){
        if(cnt[i] == 1) not_team[i] = true;
        overed[i] = true;
    }
    return ;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        int N, ans =0; cin >> N;
        memset(cnt, 0, sizeof(cnt));
        vector<int> arr(N+1);        
        vector<bool> overed(N+1, false);
        vector<bool> not_team(N+1, false);
        for(int i=1; i<=N; ++i) cin >> arr[i];
        for(int i=1; i<=N; ++i){
            if(overed[i]) continue;
            check(i, arr, not_team, overed);
        }
        for(int i=1; i<=N; ++i) if(not_team[i]) {
            ++ans;
        }
        cout << ans << '\n';
    }    
    return 0;
}