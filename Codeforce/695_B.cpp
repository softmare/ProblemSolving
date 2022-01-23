#include<iostream>

using namespace std;

void rotate(int &tag){
    tag = (tag+1)%3;
    return;
}

bool hill_or_vally(int a, int b, int c){
    if((b < a)&&(b < c) || (b>a)&&(b>c)) return true;
    return false;
}

int main(){
    int T, mem[3]; cin >> T;
    for (int t=0; t < T; t++){
        int n,cnt=0; cin >> n;
        if( n < 3) {for(int i=0, temp; i<n;i++) cin >> temp; cout << 0 << endl; continue;}
        cin >> mem[0] >> mem[1];
        for(int i=0,fr=2,tag=1, old= 0; i < n-2; i++){            
            cin >> mem[fr];
            //cout << "case " <<i << endl <<  mem[old] << ' ' << mem[tag] << ' ' << mem[fr] << endl;
            if(hill_or_vally(mem[old], mem[tag], mem[fr])) cnt++;
            rotate(old), rotate(fr), rotate(tag);
        }
        if(cnt < 3) cout << 0 << endl;
        else cout << cnt-3 << endl;
    }
    return 0;
}