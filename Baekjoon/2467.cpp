#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<int> plus, minus;
    int N,p=0,m=0, a,b; cin >> N;
    for(int n=0; n<N; ++n){
        int temp; cin>>temp;
        if(temp < 0){
            minus.push_back(temp);
        }else{
            plus.push_back(temp);
        }
    }
    sort(plus.begin(), plus.end());
    sort(minus.begin(), minus.end(), greater<int>());
    int min_dif = 1000000000;
    if(plus.size() >= 2){
        a = *plus.begin(); b = *(++plus.begin());
        min_dif = a+b;
    }
    if(minus.size() >= 2 && (abs(minus[0]+minus[1]) < min_dif)){
        min_dif = abs(minus[0]+minus[1]);
        b=minus[0]; a=minus[1];
    }
    int i, j; i=j=0; 
    while(i != plus.size() && j != minus.size()){
        int dif = plus[i] + minus[j];        
        if(abs(dif) < min_dif){
            min_dif = abs(dif);
            a = minus[j];
            b = plus[i];
        }
        if(dif < 0){
            i++;                
        }else{
            j++;                
        }
    }    
    cout << a << ' ' << b << endl;
    return 0;
}