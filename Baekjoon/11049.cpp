#include<bits/stdc++.h>

using namespace std;

long long mem[501][501];
long long arr[501];

long long dp(const int st, const int end){
    long long &ret = mem[st][end];
    if(ret != -1) return ret;
    if(end-st==2){ret = arr[st]*arr[st+1]*arr[st+2]; return ret;}
    ret = dp(st,st+1) + dp(st+1,end) + arr[st]*arr[st+1]*arr[end];
    for(int k=st+2; k<end; ++k){
        ret = min(ret, dp(st,k)+dp(k,end)+arr[st]*arr[k]*arr[end]);
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N; cin >> arr[0];
    memset(mem,-1,sizeof(mem));
    for(int i=1; i<N; ++i){
        cin >> arr[i] >> arr[i];
    }cin>> arr[N];
    
    for(int i=0; i<N; ++i){
        mem[i][i+1] = 0;
    }
    cout << dp(0,N) << '\n';
    return 0;
}