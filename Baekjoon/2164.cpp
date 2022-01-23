#include<bits/stdc++.h>

using namespace std;

int main(){
    deque<int> dq;
    bool pop = true;
    int n; cin >> n;
    for(int i=1; i<=n; ++i){
        dq.push_back(i);
    }
    while(dq.size() != 1){
        if(pop){
            dq.pop_front();
        }else{
            dq.push_back(dq.front());
            dq.pop_front();
        }
        pop ^= true;
    }
    cout << dq.front() << endl;
    return 0;
}