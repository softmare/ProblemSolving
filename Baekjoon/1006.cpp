#include<bits/stdc++.h>

using namespace std;

typedef vector<set<int> > vsi;

int N, W;

const int digoot[3][2] = {{0,2},{0,1},{1,3}};

vector<int> four_dots(const int i, const int N);
bool is_tail(vsi &edges, const int that);

void try_push(const int a, const int b, const int w, vsi &edges, vector<int> &arr){
    //cout << "try push " << a << ' ' << b << endl;
    if(arr[a]+arr[b] <= w){
        edges[a].insert(b);
        edges[b].insert(a);
    }
    return ;
}

void tail_boom(set<int> &tails, vsi &edges, int &ans){ 
    while(!tails.empty()){
        if(edges[*tails.begin()].empty()) {tails.erase(tails.begin());continue;}
        //cout << "tail : " << *tails.begin() << endl;
        --ans;
        int a, b;
        a = *tails.begin(); b = *edges[a].begin();
        tails.erase(a); edges[a].clear();
        for(int i : edges[b]){
            edges[i].erase(b);
            if(is_tail(edges, i)) {tails.insert(i);}
        }
        edges[b].clear();
    }
    return ;    
}

bool found(const int from, const int to, vsi &edges){
    return edges[from].find(to) != edges[from].end();
}

bool are_square(const int lu, const int ld, const int ru, const int rd, vsi &edges){    
    return found(lu, ld, edges) && found(lu, ru, edges) && found(ru, rd, edges) && found(ld, rd, edges);
}

bool square_boom(vsi &edges, int &ans, set<int> &tails){
    bool boomed = false;
    for(int i=0; i<N; ++i){
        vector<int> f = four_dots(i, N);
        if(are_square(f[0], f[1], f[2], f[3], edges)){
            //cout << "Boom, " << i << ' ' << N+i << ' ' << i+1 << ' ' << N+i+1 << endl;
            ans -= 2; for(int j=0; j<4; ++j) edges[f[j]].clear();
            boomed = true;
            vector<int> c = {((f[0]-1)+N)%N, (f[1]-1)%N+N, (f[2]+1)%N, ((f[3]-N+1))%N+N};
            for(int j=0; j<4; ++j) edges[c[j]].erase(f[j]);
            for(int j=0; j<4; ++j) if(is_tail(edges,c[j])) tails.insert(c[j]);
        }
    }
    return boomed;
}

vector<int> four_dots(const int i, const int N){
    vector<int> list(4); list[0] = i, list[1] = i+N; list[2] = (i+1)%N; list[3] = (N+i+1) - ((N+i+1)/(2*N))*N;
    //cout << "four dot form " << i << " " << list[0] << ' ' << list[1] << ' ' << list[2] << ' ' << list[3] << endl;
    return list;
}

bool is_tail(vsi &edges, const int that){
    return edges[that].size() == 1;
}

bool cut_line(vsi &edges, int &ans, set<int> &tails){
    bool cuted = false;
    for(int i=0;i <edges.size(); ++i){
        if(!edges[i].empty()){
            int b = *edges[i].begin(); 
            assert(edges[i].size() == 2), assert(edges[b].size() == 2);
            for(int mys : edges[i]){ edges[mys].erase(i); if(is_tail(edges,mys)) tails.insert(mys);}
            for(int mys : edges[b]){ edges[mys].erase(b); if(is_tail(edges,mys)) tails.insert(mys);}
            edges[i].clear(); edges[b].clear();
            --ans; cuted = true;
            break;
        }
    }
    return cuted;
}

void add_edges(vector<int> &arr, const int N, const int W, vsi &edges){
    if(N==1){
        try_push(0, 1, W, edges, arr);
    }else{
        for(int i=0; i<N; ++i){
            vector<int> four = four_dots(i, N);
            for(int j=0; j<3; ++j) try_push(four[digoot[j][0]], four[digoot[j][1]], W, edges, arr);
        }
    }
    return ;
}

int main(){
    // cin.tie(NULL);
    // ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        int ans; 
        cin >> N >> W; 
        ans = 2*N;
        vector<int> arr(N*2);        
        vsi edges(N*2);        
        for(int i=0; i<N*2; ++i){ cin >> arr[i]; }
        add_edges(arr, N, W, edges);
        set<int> tails;
        for(int i=0; i<N*2; ++i){
            //cout << "i : " << i << " 's edge cnt : " << edges[i].size() << '\n';
            if(edges[i].size() == 1){
                tails.insert(i);
            }
        }
        while(true){
            //cout << "round" << endl;
            if(tails.size()) {tail_boom(tails, edges, ans);}
            if(!square_boom(edges, ans, tails)) {
                if(!cut_line(edges, ans, tails));
                    break;
            }
            //cout << "square boom , ans : " << ans << '\n';
        }
        // tail_boom(tails, edges, ans);
        // for(int i=0; i<2*N-1; ++i){
        //     cout << i << "st edges : ";
        //     for(auto j : edges[i]){
        //         cout << j << ' ';
        //     }cout << '\n';
        // }
        cout << ans << '\n';
    }
    return 0;
}