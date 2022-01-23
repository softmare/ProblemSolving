#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int parent(int id, int i){
    return id >> i;
}

int left_child(int id){
    return id << 1;
}

int right_child(int id){
    return (id << 1) + 1;
}

void init(const int arr_begin, vector<ll> &arr){
    for(int k = arr_begin>>1; k; k>>=1){        
        for(int i=k; i< k<<1; ++i){
            arr[i] = arr[left_child(i)] + arr[right_child(i)];
        }
    }
    return;
}

int level(int id){
    int k(0); while(id) {id>>=1; ++k;}
    return k;
}

ll psum(const int st, const int end, const int node, const int arr_begin, vector<ll> &arr){
    int k(level(arr_begin) - level(node));
    int n_st(node<<k), n_end((node<<k)+(1<<k)-1);
    if(n_st > end || n_end < st) return 0;
    if(n_st == st && n_end == end) return arr[node];
    const int _end(min(end, (((node<<1)+1)<<k-1)-1)), _st(max(st, (node<<1)+1<<k-1));
    return psum(st, _end, node<<1, arr_begin, arr) + psum(_st, end, (node<<1)+1, arr_begin, arr);
}

ll update(const int id, const int node, const ll &val, vector<ll> &arr){
    if(id == node) {arr[id] = val; return val;}
    int a((id>>(level(id)-level(node)-1))&1), b; b=a^1;
    arr[node] = update(id, (node<<1)+a, val, arr) + arr[(node<<1)+b];
    return arr[node];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, K; cin >> N >> M >> K;
    int arr_begin = 1;
    while(N > arr_begin) {arr_begin <<= 1;}
    vector<ll> arr(arr_begin<<1);
    for(int i=arr_begin; i<arr_begin+N; ++i){
        cin >> arr[i];
    }
    init(arr_begin, arr);
    for(int i=0; i<M+K; ++i){
        long long a,b,c; cin >> a >> b >> c;
        if(a==1){
            update(arr_begin+b-1, 1, c, arr);
        }else{
            cout << psum(arr_begin+b-1, arr_begin+c-1, 1, arr_begin, arr) << '\n';
        }
    }
    return 0;
}

/*
배열 이용한 2분 트리(부모노드가 >> 1 한 번호. 자식트리가 << 1 하고 0 또는 1 더한 번호)

이용해서 더 해보기.
*/