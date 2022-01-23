#include<bits/stdc++.h>

using namespace std;
priority_queue<int> pq;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    for(int n=0; n<N; ++n){
        int ip; cin >> ip;
        if(!ip){
            if(pq.empty()) cout << 0 << '\n';
            else{
                cout << pq.top() <<'\n';
                pq.pop();
            }
        }else{
            pq.push(ip);
        }
    }
    return 0;
}