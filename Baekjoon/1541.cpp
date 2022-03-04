#include<bits/stdc++.h>

using namespace std;

bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

int main()
{
    string s;
    cin >> s;
    int sum = 0;
    int num = 0;
    char lastSymbol = '+';
    bool minusFound = false;
    for(int i=0; i < s.length(); ++i)
    {
        char &c = s[i];
        if(isDigit(c))
        {
            num *=10;
            num += (c - '0');
        }else{
            if(lastSymbol == '+')
            {
                sum = minusFound ? sum - num : sum + num;
            }else{
                minusFound = true;
                sum -= num;
            }
            num = 0;
            lastSymbol = c;
        }
    }
    sum = (minusFound || lastSymbol == '-') ? sum - num : sum + num;
    cout << sum << endl;
    return 0;
}