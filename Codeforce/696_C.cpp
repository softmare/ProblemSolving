#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    int T; cin >> T;
    for(int t=0; t<T; t++){
        multiset<int> s,st;
        int n; cin >> n; n *= 2;
        int ans[2000];
        for(int i=0,tp; i<n; i++){
            cin >> tp; s.insert(tp);
        }
        bool rsuc = false;
        for(auto it = ++(s.rbegin()); it!= s.rend(); it++){
            st = s;
            int tar = *(s.rbegin());
            //cout << "*it : " << *it << " tar : " << tar << endl;
            ans[0] = *it;
            ans[1] = tar;
            st.erase(--(st.end()));
            st.erase(st.find(*it));
            int nd = 2;
            bool suc = false;            
            while(true){
                if(st.empty()) {suc = true; break;}
                int big = *st.rbegin();
                st.erase(--st.end());
                auto ri = st.find(tar-big);
                if(ri != st.end()){
                    //cout << "ri : " << *ri << " bing : " << big << endl;
                    ans[nd++] = *ri;
                    ans[nd++] = big;
                    tar = big;
                    st.erase(ri);
                    continue;
                }
                break;
            }
            if(suc) {rsuc = true; break;}
        }
        if(rsuc) {
            cout << "YES" << endl << ans[0]+ans[1] << endl;
            for(int i=0; i< n; i+=2){
                cout << ans[i] << ' ' << ans[i+1] << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }


    return 0;
}