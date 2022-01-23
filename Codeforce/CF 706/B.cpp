#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        int n, k, ans; cin >> n >> k;
        vector<int> v(n);
        for(int i=0; i<n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        int mex = -1;
        for(int i=0; i<n; ++i){
            if(v[i] != i){
                mex = i;
                //cout << " mex : " << mex << endl;                
                break;
            }
        }
        if(!k){ans = n;}
        else if(mex == -1) {ans = n + k;}
        else{
            auto it = find(v.begin(), v.end(), (int)ceil((mex+v[n-1])/2));        
            //cout << *it << ' ' << it - v.begin() << ' ' << (int)ceil((mex+v[n-1])/2) << endl;
            if(it != v.end()) ans = n;
            else ans = n+1;
        }
        cout << ans << '\n';
    }
    return 0;
}