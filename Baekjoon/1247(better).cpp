#include <bits/stdc++.h>

using namespace std;

int main(){
    for(int t = 0; t<3; ++t) {
        int n;
        long long sum(0), inp(0), over(0);
        cin >> n;
        for(int i=0; i<n; ++i){
            cin >> inp;
            if (inp>0&&sum>0&&sum>LLONG_MAX-inp) {++over;}
            else if (inp<0&&sum<0&&sum<LLONG_MIN-inp) {--over;}
            sum += inp;
        }
        if (over > 0) {cout << "+\n";}
        else if (over < 0) {cout << "-\n";}
        else {
            if (sum > 0) {cout << "+\n";}
            else if (sum < 0) {cout << "-\n";}
            else {cout << "0\n";}
        }
    }
    return 0;
}