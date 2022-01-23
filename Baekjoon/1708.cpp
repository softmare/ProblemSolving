#include<bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pll;

pll operator+(const pll a, const pll b){
    return pll(a.first+b.first, a.second+b.second);
}

pll operator-(const pll a, const pll b){
    return pll(a.first-b.first, a.second-b.second);
}

long long naejuck(pll &me, pll &that){ // 양수면 왼쪽, 음수면 오른쪽. 0 이면 같다.
    return me.first*that.second - me.second*that.first;
}

double cos(const long long x, const long long y){
    return x/sqrt(x*x+y*y);
}

bool lowest_first(const pll a, const pll b){
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

bool rclockwise(const pll a, const pll b){
    long long const &ax = a.first, &ay = a.second, &bx = b.first, &by = b.second;
    double cores = cos(ax, ay) - cos(bx, by);
    return cores > 0;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, ans = 1; cin >> N; vector<pll> v(N);
    for(int i=0; i<N; ++i)
    cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), lowest_first);
    for(int i=1; i<N; ++i){
        v[i].first -= v[0].first, v[i].second -= v[0].second;
    }v[0] = {0,0};
    sort(v.begin()+1, v.end(), rclockwise);
    v.push_back(v[0]);        
    int b(0), c(1);
    vector<pair<pll,int> > vecs; vecs.push_back({v[1]-v[0], 1});
    for(int i=2; i<N+1; ++i){
        b = vecs.back().second; c = i;
        pll ab, bc; ab = vecs.back().first, bc = v[c] - v[b];
        long long nae = naejuck(ab, bc);
        if(nae == 0){
            vecs.back().second = c;
        }else if(nae > 0){
            vecs.push_back({bc, c});
        }else{
            while(nae < 0){
                vecs.pop_back();
                b = vecs.back().second; ab = vecs.back().first, bc = v[c] - v[b];
                nae = naejuck(ab,bc);
                if(nae == 0){
                    vecs.back().second = c;
                }else if(nae > 0){
                    vecs.push_back({bc, c});
                }
            }
        }
    }
    // cout << "--" << endl;
    // for_each(v.begin(), v.end(), [](pll a){cout << a.first << ' ' << a.second << endl;});
    // cout << "--" << endl;
    // for_each(vecs.begin(), vecs.end(), [&v](pair<pll, int> a){cout << v[a.second].first << ' ' << v[a.second].second << endl;});
    // cout << "--" << endl;
    cout << vecs.size() << '\n';
    return 0;
}
