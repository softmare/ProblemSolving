#include<bits/stdc++.h>

using namespace std;

int mem[1001][1001];

int dp(int i, int j, string &a, string &b){
    int &ret = mem[i][j];
    if(ret != -1) return ret;
    int add = a[i-1] == b[j-1] ? 1 : 0;
    ret = max(max(dp(i-1, j-1, a, b) + add, dp(i-1, j, a, b)), dp(i, j-1, a, b));    
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(mem, -1, sizeof(mem));
    for(int i=0; i <1001; ++i){
        mem[0][i] = mem[i][0] = 0;
    }    
    string a, b; cin >> a >> b;
    dp(a.length(), b.length(), a, b);
    cout << mem[a.length()][b.length()] << endl;
    return 0;
}