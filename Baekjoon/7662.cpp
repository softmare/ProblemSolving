#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, T;
    cin >> N;
    for(int n=0; n<N; ++n){
        cin >> T;
        multiset<int> ms;
        for(int t=0; t<T; ++t){
            char c; int temp;
            cin >> c >> temp;
            if(c == 'I'){
                ms.insert(temp);
            }else{
                if(ms.empty()) continue;
                ms.erase((temp == -1 ? ms.begin() : --ms.end()));                                
            }            
        }
        if(ms.empty()){
            cout << "EMPTY" << '\n';
        }else{
            cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}