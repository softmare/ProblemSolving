#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int T; cin >> T;
    for(int t=0; t<T; t++){
        int n; cin >> n;
        string a, b; cin >> b;
        a+= '1';
        for(int i=1;  i < n; i++){
            //cout << "i : " << i << (int(b[i])+1) << ' ' << (int(a[i-1])+int(b[i-1])) << endl;
            if((b[i]-'0'+1)==(a[i-1]-'0'+b[i-1]-'0')){

                a+='0';
            }else{
                a+='1';
            }
        }
        cout << a << endl;
    }
    return 0;
}