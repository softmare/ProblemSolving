#include<bits/stdc++.h>

using namespace std;
set<int> st;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);    
    int N; cin >> N;
    for(int n=0; n<N; ++n){
        string s; int temp;
        cin >> s;
        if(!(s == "all" || s == "empty")){
            cin >> temp;
        }
        if(s[1] == 'd'){
            st.insert(temp);
        }else if(s[0] == 'c'){
            cout << (st.find(temp) != st.end() ? 1 : 0) << '\n';
        }else if (s[0] == 't'){
            set<int>::iterator it = st.find(temp);
            if(it == st.end()) st.insert(temp);
            else st.erase(it);
        }else if(s[1] == 'l'){
            for(int i=1; i<21; ++i){
                st.insert(i);
            }
        }else if(s[0] == 'r'){
            st.erase(temp);
        }else if(s[0] == 'e'){
            st.clear();
        }else{
            assert(0);
        }
    }
    
    return 0;
}

