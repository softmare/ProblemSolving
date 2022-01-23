#include<bits/stdc++.h>

using namespace std;
map<int, int> mp;
set<int> st;
vector<int> v;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N; cin >> N;
    for(int n=0; n<N; ++n){
        int temp; cin>>temp;
        v.push_back(temp);
        st.insert(temp);
    }
    int a = 0;
    for(auto it=st.begin(); it!=st.end();++it){
        mp[*it] = a++;
    }
    for(auto i : v){
        cout << mp[i] << ' ';
    }
    return 0;
}