#include<bits/stdc++.h>

using namespace std;

int arr[2000];
int isPal[2000][2000];

void init(){
    for(int i=0; i<1999; ++i){
        isPal[i+1][i] = isPal[i][i] = 1;        
    }
    isPal[1999][1999] = 1;
    return;
}

bool isPaal(const int S, const int E){
    int &ret = isPal[S][E];
    if(ret != -1) return ret;
    if(S==E) return 1;
    if(isPaal(S+1,E-1) && arr[S] == arr[E]) {ret = 1; return 1;}
    ret=0;
    return 0;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(isPal,-1, sizeof(isPal));
    init();
    int N, M; cin >> N;    
    for(int n=0; n<N; ++n) cin>>arr[n];
    cin >> M;
    for(int i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        cout << isPaal(a-1,b-1) << '\n';
    }
    return 0;
}