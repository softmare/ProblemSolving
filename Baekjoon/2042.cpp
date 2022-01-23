#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

long long inp[1000001];

struct node{
    int st;
    int end;
    long long sum;
    node *parent, *left, *right;
    node(int st, int end, node *p) : st(st), end(end), parent(p){};
};

long long init(int st, int end, node &me){
    //cout << "init st : " << st << " end : " << end << endl;
    if(st==end) {me.sum = inp[st]; return me.sum;}
    const int mid = (st+end)/2;
    me.left = new node(st, mid, &me);
    me.right = new node(mid+1, end, &me);
    me.sum = init(st, mid, *me.left) + init(mid+1, end, *me.right);
    return me.sum;
}

long long psum(const int st, const int end, node *me){
    if(end < me->st || st > me->end) return 0;
    if(me->st == st && me->end == end) return me->sum;
    const int _end = min(end, me->left->end), _st = max(st, me->right->st);    
    return psum(st, _end, me->left) + psum(_st, end, me->right);
}

long long correction(const int &n, const long long &val, node *me){
    if(me->st == me->end) {me->sum = val; return me->sum;}
    node *a(me->left), *b(me->right); // n이 소속된 것이 a가 된다.
    if(b->st <= n) swap(a,b);
    me->sum = b->sum + correction(n, val, a);
    return me->sum;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, K; cin >> N >> M >> K;
    for(int i=1; i<=N; ++i) cin >> inp[i];
    node root(1, N, nullptr);
    init(1, N, root);
    for(int i=0; i<(M+K); ++i){
        long long a, b, c; cin >> a >> b >> c;
        if(a == 1){
            correction(b, c, &root);
        }else{
            cout << psum(b, c, &root) << '\n';
        }
    }
    return 0;
}