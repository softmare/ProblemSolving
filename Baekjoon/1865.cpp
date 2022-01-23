#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;

struct pcmp{
    bool operator()(const pair<int, int> a, const pair<int, int> b) const{
        return a.second > b.second;
    }
};

int sp(const int st, const int N, vector<map<int, int> > &ns){
    priority_queue<pair<int, int>, vector<pair<int,int> >, pcmp > pq;
    pq.push(pair<int, int>(st, 0));
    bool painted[501];
    for(int i=0; i< 501; ++i){
        painted[i] = false;
    }
    int shortest = 0;
    while(!pq.empty()){
        auto pr = pq.top();
        pq.pop();
        //cout << "i'm : " << pr.first << " weight : " << pr.second << endl;
        if(pr.first == st){
            shortest = min(shortest, pr.second);
        }
        if(!painted[pr.first]){
            painted[pr.first] = true;
            for(auto mpr : ns[pr.first]){
                //cout << "mpr f : " << mpr.first << " sec : " << mpr.second<<endl;
                pq.push(pair<int,int>(mpr.first, pr.second+mpr.second));
            }
        }        
    }
    return shortest;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, N, M, W; cin >> T;
    for(int t=0; t<T; ++t){
        bool possible = false;        
        cin >> N >> M >> W;
        set<int> ws;
        vector<map<int, int> > ns(N+1);
        for(int m=0; m<M; ++m){            
            int a, b, c; cin >> a >> b >> c;
            ns[a][b] = (ns[a].find(b) != ns[a].end()) ? min(ns[a][b], c) : c;
            ns[b][a] = ns[a][b];
            
        }
        for(int w=0; w<W; ++w){            
            int a, b, c; cin >> a >> b >> c;
            ns[a][b] = (ns[a].find(b) != ns[a].end()) ? min(ns[a][b], -c) : -c;      
            ws.insert(a);      
        }        
        for(int w : ws){            
            if(sp(w, N, ns) < 0){
                possible = true;
                break;
            }
        }
        cout << (possible? "YES" : "NO") << '\n';
    }
    
    return 0;
}