#include<bits/stdc++.h>

using namespace std;

int T, a, b;

int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        cin >> a >> b;
        int m = 987654321, add = 0;
        if(b == 1){
            add++;           
        }
        while(true){
            int a_ = a, b_ = b+add, cnt = add;
            if(add >=  m){
                break;
            }
            while(a_){
                a_ /= b_;
                cnt++;
            }
            m = min(m, cnt);
            ++add;
        }
        cout << m << endl;
    }


    return 0;
}