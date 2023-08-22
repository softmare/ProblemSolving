#include <bits/stdc++.h>

using namespace std;

int table[64][64];

string parser(const int length, const int py, const int px)
{
    string s;
    if(length == 1)
    {
        s += to_string(table[py][px]);
        return s;
    }else{
        const int hlength = length/2;
        s += parser(hlength, py, px);
        s += parser(hlength, py , px + hlength);
        s += parser(hlength, py + hlength, px);
        s += parser(hlength, py + hlength, px + hlength);

        if(s == "0000")
        {
            return "0";
        }else if(s == "1111")
        {
            return "1";
        }else{
            return '(' + s + ')';
        }
    }
}

int main()
{
    int length; cin >> length;
    for(int r=0; r<length; ++r)
    {
        string inp; cin >> inp;
        for(int c=0; c<length; ++c)
        {
            table[r][c] = inp[c] - '0';
        }
    }

    cout << parser(length, 0, 0);
    return 0;
}