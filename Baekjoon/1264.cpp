#include <iostream>

using namespace std;

int main(){
    
    while (true) {
        string s;
        getline(cin, s);
        if (s == "#") break;
        int cnt = 0;
        const char *vowels = "aeiouAEIOU";
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 10; ++j){
                if (s[i] == vowels[j]) {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}