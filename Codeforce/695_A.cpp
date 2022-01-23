#include<iostream>
 
using namespace std;
 
int main(){
    int t; cin >> t;
    for (int i=0,n; i < t; i++){
        cin >> n;
        if(n/10 > 0){
            for(int i=0; i < n/10 ; i++) cout << "9876543210";
            for(int i=0,base=1; i <n%10; i++){
                cout << base++;
            }
        }else{
            for(int i=0,base=9; i <n%10; i++){
                cout << base--;
            }
        }
        cout << endl;
    }
    return 0;
}