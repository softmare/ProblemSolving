#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

struct node{
    int branch_id;
    int level;
    int upper_branch;
    ii parent;
    vector<ii> edges;
    int cost_for_upper_branch;
};

node nodes[40001];
int N;
bool painted[40001];

bool is_branch(int me){
    return nodes[me].edges.size() >2;
}

void fill(int me, int from, int cost_bt_mefrom, int upper_branch, int level, int &branch, int cost_for_upper_branch){
    painted[me] = true;
    nodes[me].level = level;
    nodes[me].parent = {from,cost_bt_mefrom};
    nodes[me].branch_id = branch;
    nodes[me].cost_for_upper_branch = cost_for_upper_branch;    
    nodes[me].upper_branch = upper_branch;
    if(is_branch(me)){        
        for(ii pr : nodes[me].edges){
            if(painted[pr.first]) continue;
            fill(pr.first, me, pr.second, me, level+1, ++branch, pr.second);
        }
    }else{
        for(ii pr : nodes[me].edges){
            if(painted[pr.first]) continue;
            fill(pr.first, me, pr.second, upper_branch, level+1, branch, cost_for_upper_branch+pr.second);
        }
    }
    painted[me] = false;
    return ;
}

int dist_for_same_br(int a, int b){ // 레벨이 더 높은 것을 b로 입력.    
    return nodes[b].cost_for_upper_branch - nodes[a].cost_for_upper_branch;
}

int dist(int a, int b){
    int cost(0);
    while(a!=b){
        if(nodes[a].level > nodes[b].level) swap(a,b);
        if(nodes[a].branch_id == nodes[b].branch_id){
            cost += dist_for_same_br(a, b);
            break;
        }
        cost += nodes[b].cost_for_upper_branch;
        b = nodes[b].upper_branch;
    }
    return cost;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N;
    for(int i=0; i<N-1; ++i){
        int a, b, w; cin >> a >> b >> w;
        nodes[a].edges.push_back({b,w});
        nodes[b].edges.push_back({a,w});
    }    
    painted[0] = true;
    nodes[1].edges.push_back({0,0});
    int branch_id(0);
    fill(1, 0, 0, 1, 0, branch_id, 0);
    cin >> M;
    for(int i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        cout << dist(a, b) << '\n';
    }
    return 0;
}