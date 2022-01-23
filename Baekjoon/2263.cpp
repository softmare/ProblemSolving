#include<bits/stdc++.h>

using namespace std;

struct Info{
    int L, R;
    Info(int l=-1, int r=-1) : L(l), R(r) {};
};

void dq(int a, int b, vector<int>::reverse_iterator &it, vector<int> &in, vector<Info> &info){
    //cout << "a : " << a << " b : " << b << " *it : " << *it << endl;
    int me = *it++;
    if(in[me]+1 <= b){
        info[me].R = *it;    
        dq(in[me]+1, b, it, in, info);
    }
    if(a <= in[me]-1){
        info[me].L = *it;
        dq(a,in[me]-1, it, in, info);
    }
    return ;
}

void pt(int me, vector<Info> &info){
    cout << me << ' ';
    if(info[me].L != -1) pt(info[me].L, info);
    if(info[me].R != -1) pt(info[me].R, info);
    return ;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> in(N+1), post(N);
    vector<Info> info(N+1);
    for(int i=1; i<N+1; ++i) {
        int tm; cin >> tm; in[tm] = i;        
    }
    for(int i=0; i<N; ++i) {
        cin >> post[i];
    }
    auto it = post.rbegin();
    dq(1, N, it, in, info);
    pt(*post.rbegin(), info);
    return 0;
}