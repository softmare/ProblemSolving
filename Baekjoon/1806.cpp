#include<bits/stdc++.h>

using namespace std;

int arr[100000];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, S, ans = 987654321; cin >> N >> S;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }
    int a(0), b(1), stack(arr[0]), cur_len(1);
    while(true){        
        if(stack<S){
            if(b == N) break;
            stack += arr[b++];
            ++cur_len;
        }else{
            ans = min(ans, cur_len--);
            stack -= arr[a++];
        }
    }
    cout << (ans == 987654321 ? 0 : ans) << endl;
    return 0;
}