#include<bits/stdc++.h>

using namespace std;

map<int, long long> m;

long long dq(const int a, int b, const int c){
    if(m.find(b)!=m.end()){
        return m[b];
    }
    int d = b/2;
    m[b] = (dq(a, d, c) * dq(a, b-d, c))%c;
    return m[b];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    m[1] = a % c;
    cout << dq(a, b, c) << endl;
    return 0;
}