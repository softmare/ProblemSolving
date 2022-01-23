#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pr;

bool comp(pr a, pr b){
    return a.first > b.first;
}

int N, ans;
vector<pr> v;
priority_queue<int> pq;

int main(){
    cin >> N;
    for(int i=0; i< N; i++){
        int d, w; cin >> d >> w;
        v.push_back(pr(d,w));
    }
    sort(v.begin(), v.end(), comp);
    
    for(int id=1000,vi=0;id > 0; id--){        
        while(vi < N && v[vi].first == id){
            pq.push(v[vi++].second);
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;

    return 0;
}