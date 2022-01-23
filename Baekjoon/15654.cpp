#include<bits/stdc++.h>

using namespace std;

bool painted[10];

void dfs(int me, int left, vector<int> &stack, const int N, vector<int> &list){
    if(!left){
        for(int i : stack){
            cout << list[i] << ' ';
        }cout << '\n';
        return;
    }
    for(int i=0; i<N; ++i){
        if(painted[i]) continue;
        painted[i] = true;
        stack.push_back(i);        
        dfs(i, left-1, stack, N, list);
        stack.pop_back();
        painted[i] = false;
    }
    return ;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<int> stack, list;
    for(int i=0; i<N; ++i){
        int tm; cin >> tm;
        list.push_back(tm);
    }
    sort(list.begin(),list.end(),less<int>());
    dfs(0, M, stack, N, list); 
    return 0;
}

