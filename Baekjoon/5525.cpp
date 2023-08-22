#include<bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, length; cin >> N >> length;
    string s; cin >> s;
    int state(0), cnt(0), sum(0);
    const char O='O', I='I';
    for(char c : s)
    {
        switch(state)
        {
            case 0:
            if(c == I)
            {
                state = 1;
            }
            break;
            case 1:
            if(c == O)
            {
                state = 2;
            }
            break;
            case 2:
            if(c == O)
            {
                state = 0;
                cnt = 0;
            }else{
                state = 3;
                if(++cnt >= N)
                {
                    ++sum;
                }
            }
            break;
            case 3:
            if(c == O)
            {
                state = 2;
            }else{
                state = 1;
                cnt = 0;
            }
        }
    }
    cout << sum << endl;
    return 0;
}