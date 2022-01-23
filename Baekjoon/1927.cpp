#include<bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>,greater<int> > heap;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0; i<n; ++i){
        int temp; cin >> temp;
        if(temp == 0){
            if(heap.empty()) cout << 0 << '\n';
            else{
                cout << heap.top() << '\n';
                heap.pop();
            }
        }else{
            heap.push(temp);
        }
    }
    return 0;
}