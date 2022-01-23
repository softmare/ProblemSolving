#include<bits/stdc++.h>

using namespace std;

int table[1000][1000];
string A, B, rans;

int dp_fill(const int a, const int b){
    if(a<0 || b<0) return 0;
    int &ret=table[a][b];
    if(ret != -1) return ret;
    if(A[a] == B[b]) ret = dp_fill(a-1,b-1) + 1;
    else{ ret = max(dp_fill(a-1,b), dp_fill(a,b-1));}
    return ret;
}

void dp_ans(const int a, const int b){
    if(a < 0 || b < 0) return;
    if(A[a] == B[b]){
        rans += A[a];
        dp_ans(a-1,b-1);
    }else{
        if(dp_fill(a-1,b) < dp_fill(a,b-1)){
            dp_ans(a,b-1);
        }else{
            dp_ans(a-1,b);
        }
    }
    return ;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> A >> B;
    memset(table,-1,sizeof(table));
    cout << dp_fill(A.size()-1, B.size()-1) << '\n';
    dp_ans(A.size()-1, B.size()-1);
    for_each(rans.rbegin(),rans.rend(),[](char c){cout << c;});
    cout << '\n';
    return 0;
}