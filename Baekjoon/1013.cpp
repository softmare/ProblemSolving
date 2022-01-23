#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<int> v;
    int n; cin >> n;
    for(int t=0; t<n; t++){
        int state = 0;
        string s;
        cin >> s;
        for(int i=0; i != s.length();i++){
            //cout << "state : " << state << "  s[i] : " << s[i] << endl;;
            if(state == 8) break;
            switch(state){
                case 0:
                if(s[i]=='1'){
                    state=1;
                }else{state=7;}
                break;
                case 1:
                if(s[i]=='1'){
                    state=8;
                }else{state=2;}
                break;
                case 2:
                if(s[i]=='1'){
                    state=8;
                }else{state=3;}
                break;
                case 3:
                if(s[i]=='1'){
                    state=4;
                }
                break;
                case 4:
                if(s[i]=='1'){
                    state=5;
                }else{state=7;}
                break;
                case 5:
                if(s[i]=='1'){
                    
                }else{state=6;}
                break;
                case 6:
                if(s[i]=='1'){
                    state=0;
                }else{state=3;}
                break;
                case 7:
                if(s[i]=='1'){
                    state=0;
                }else{state=8;}
                break;
                

            }
        }
        //cout << "final state : " << state << endl;
        if(state == 0 || state == 4 || state == 5) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}