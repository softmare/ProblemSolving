#include<bits/stdc++.h>

using namespace std;

void dfs(int me, int left, vector<int> &stack, const int N){
    stack.push_back(me);
    if(!left){
        for(auto it = stack.begin()+1; it != stack.end(); ++it){
            cout << *it << ' ';
        }cout << '\n';        
        stack.pop_back();
        return ;
    }
    for(int i = me+1; N-i+1>=left; ++i){
        dfs(i, left-1, stack, N);
    }
    stack.pop_back();
    return ;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    vector<int> stack;
    dfs(0, M, stack, N); 
    return 0;
}