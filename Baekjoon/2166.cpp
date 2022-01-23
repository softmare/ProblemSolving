#include<bits/stdc++.h>

using namespace std;

double xy[10000][2];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        cin >> xy[i][0] >> xy[i][1];        
    }
    double a=0, b=0;
    for(int i=0; i<N; ++i){
        a += xy[i][0] * xy[i+1][1];
        b += xy[i][1] * xy[i+1][0];
    }
    a += xy[N-1][0] * xy[0][1];
    b += xy[N-1][1] * xy[0][0];
    cout << fixed << setprecision(1) << round(abs(a - b)*10)/20 << endl;
    return 0;
}