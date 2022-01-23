#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    long long cnt = 0;
    const int NN = N*N;
    vector<int> A(N), B(N), C(N), D(N);
    vector<int> AB, CD;
    vector<int> AB_jump(N*N), CD_jump(N*N);
    for(int i=0; i<N; ++i){
        cin >> A[i] >> B[i] >> C[i] >> D[i];        
    }
    for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j){
        AB.push_back(A[i]+B[j]);
        CD.push_back(-C[i]-D[j]);
    }
    sort(AB.begin(), AB.end()); // 음 -> 양
    sort(CD.begin(), CD.end()); // 음 -> 양 같은 수 찾기.
    int AB_jc = 1, CD_jc = 1;
    AB_jump[NN-1] = CD_jump[NN-1] = 1;
    for(int i = NN-2; i>=0; --i){
        AB_jump[i] = AB[i+1] == AB[i] ? ++AB_jc : AB_jc = 1;
        CD_jump[i] = CD[i+1] == CD[i] ? ++CD_jc : CD_jc = 1;
    }
    int ab = 0, cd = 0;
    while(ab != NN && cd != NN){
        if(AB[ab] < CD[cd]){
            ab += AB_jump[ab];
        }else if(AB[ab] > CD[cd]){
            cd += CD_jump[cd];
        }else{
            cnt += (long long)AB_jump[ab] * CD_jump[cd];
            ab += AB_jump[ab];
            cd += CD_jump[cd];
        }
    }
    cout << cnt << '\n';

    // for(int i=0; i<N*N; ++i){
    //     cout << "AB [" << i << "] : " << AB[i] << " and AB_jump : " << AB_jump[i] << endl;
    // }
    // for(int i=0; i<N*N; ++i){
    //     cout << "CD [" << i << "] : " << CD[i] << " and CD_jump : " << CD_jump[i] << endl;
    // }
    return 0;
}