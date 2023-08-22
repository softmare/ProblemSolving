#include <iostream>
#include <string>

using namespace std;

struct MyInt {
    int n[30];
    MyInt operator+ (const MyInt &b){
        MyInt c("0");
        char carry = 0;
        for (int i = 0; i < 30; ++i){
            char sum = n[i] + b.n[i] + carry;
            c.n[i] = sum % 10;
            carry = sum / 10;
        }
        return c;
    }
    MyInt(const string &s) {
        bool sign = s[0] != '-';
        for (int i = 0; i < 30; ++i) n[i] = 0;
        if (sign) {
            // cout << "sign is plus" << endl;
            int i = 0;
            for (auto r = s.rbegin(); r != s.rend(); ++r){
                n[i] = *r - '0';
                ++i;
            }
        } else {
            string b("");
            string t = s.substr(1);
            t = string(30 - t.length(), '0') + t;
            for (auto p = t.begin(); p != t.end(); ++p){
                b.push_back('9' - *p + '0');
            }
            // cout << "b = " << b << endl;
            *this = MyInt(b) + MyInt("1");
        }
    }
    bool isZero(){
        for (size_t i = 0; i < 30; i++)
        {
            if (n[i] != 0) return false;
        }
        return true;
        
    }

    void print() {
        for (int i=29; i >= 0; --i){
            if(n[i] == 0) continue;
            else {
                for (; i>=0; --i){
                    cout << n[i];
                }
                break;
            }
        }cout << endl;
    }
};

int main() {
    double sum;
    for (int t = 0; t<3; ++t){
        int n;
        cin >> n;
        MyInt sum("0");
        for (int i = 0; i < n; ++i){
            string a;
            cin >> a;
            sum = sum + MyInt(a);
        }
        // sum.print();
        if (sum.n[29] > 4) cout << "-\n";
        else if (sum.isZero()) cout << "0\n";
        else cout << "+\n";
    }
    // while (true){
    //     string a, b;
    //     cin >> a >> b;
    //     MyInt(a).print();
    //     MyInt(b).print();
    //     (MyInt(a) + MyInt(b)).print();
    // }
    return 0;
}