#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

bool is_p(int a){
    if(a<=1) return false;
    double sa = sqrt(double(a));
    for (int n=2; n<=sa; n++){
        if(a%n) continue;
        return false;
    }
    return true;
}

int main(){
    int T; cin >> T;
    for(int t=0; t<T; t++){
        int d,b,c; cin >> d; 
        for(int i=1+d;;i++){
            if(is_p(i)) { b = i; break;}
        }
        for(int i=b+d;;i++){
            if(is_p(i)) { c = i; break;}
        }
        cout << c*b << endl;
    }
    return 0;
}