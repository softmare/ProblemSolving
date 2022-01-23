#include<bits/stdc++.h>

using namespace std;

int nearest_branchOf[50001];
int levelOf[50001];
bool painted[50001];
int branch_numOf[50001];

void check(const int me, int &branch_num, int nearest_branch, const int level, vector<vector<int> > &edgeOf){
    if(painted[me]) return;
    levelOf[me] = level;
    nearest_branchOf[me] = nearest_branch;
    painted[me] = true;
    branch_numOf[me] = branch_num;
    for(int childCnt=0, i=0; i<edgeOf[me].size(); ++i){
        if(!painted[edgeOf[me][i]]) ++childCnt;
        if(childCnt > 1) {nearest_branch = me; break;}
    }
    for(int i=0; i<edgeOf[me].size(); ++i){
        if(!painted[edgeOf[me][i]]) {
            if(nearest_branch == me) ++branch_num;
            check(edgeOf[me][i], branch_num, nearest_branch, level+1, edgeOf);
        }
    }
    painted[me] = false;
    return ;
}



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, brn=0; cin >> N;
    vector<vector<int> > edgeOf(N+1); 
    for(int i=0; i<N-1; ++i){
        int a, b; cin >> a >> b;
        edgeOf[a].push_back(b);
        edgeOf[b].push_back(a);
    }
    check(1, brn, 1, 0, edgeOf);
    cin >> M;
    for(int i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        while(a != b){
            if(branch_numOf[a] == branch_numOf[b]){
                if(levelOf[a] > levelOf[b]) a = b;
                else b = a;
                break;
            }
            if(levelOf[a] > levelOf[b]){                
                a = nearest_branchOf[a];
                continue;
            }else if(levelOf[a] < levelOf[b]){                
                b = nearest_branchOf[b];
                continue;
            }else{                
                a = nearest_branchOf[a];
                b = nearest_branchOf[b];
            }
        }
        cout << a << '\n';
    }
    // for(int i=1; i<=N; ++i){
    //     cout << i <<". level : " << levelOf[i] << " NB : " << nearest_branchOf[i] << " BN : " << branch_numOf[i] << endl;
    // }
    return 0;
}