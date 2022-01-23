#include<bits/stdc++.h>

using namespace std;
map<char, int> priority;

void process(string &ans, vector<char> &stack, string &inp, const int i){
    char sbc, c = inp[i];    
    if(!stack.empty()) sbc = stack.back();
    //cout << "c : " << c << " sbc : " << sbc << endl;
    if(c == '^' || c == '('){
        stack.push_back(c);
    }else if (c == ')')
    {
        sbc = stack.back();            
        stack.pop_back();
        while(sbc !='(') {
            ans += sbc;
            sbc = stack.back();
            stack.pop_back();
        }
    }else if (c == '$')
    {
        sbc = stack.back();
        stack.pop_back();
        while(sbc != '^') {
            ans += sbc;
            sbc = stack.back();
            stack.pop_back();
        }
    }else if (isalpha(c)){ ans += c; }
    else{
        sbc = stack.back();
        while(priority[c] <= priority[sbc]){            
            stack.pop_back();
            ans += sbc;
            sbc = stack.back();
        }
        stack.push_back(c);        
    }
    return;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string ans, inp;
    vector<char> stack;
    priority['^'] = 0;
    priority['('] = 1;
    priority['-'] = 2;
    priority['+'] = 2;
    priority['/'] = 4;
    priority['*'] = 4;
    cin >> inp;
    inp = '^' + inp + '$';
    int i=0;
    while(i < inp.size()){        
        process(ans, stack, inp, i++);
    }
    cout << ans << endl;
    return 0;
}