#include<bits/stdc++.h>

using namespace std;

void getPi(string &p, vector<int> &pi){
    for(int i=1, j=0; i < )
}


int main(){
    //찾을 패턴. 여자는 와일드카드. 남자는 F. 팀이 FFMMFF면 ..FF.. 인 패턴을 찾는다.
    //오토마타를 만들어 푼다.

    int T; cin >> T;
    for(int t=0; t<T; ++t){
        string p, t; cin >> p >> t;
        for(auto it=p.begin(); it!=p.end(); ++it){
            *it = *it == 'M' ? 'F' : '.';
        }
        vector<int> pi(p.length());
        getPi(p, pi);
    }


    return 0;
}