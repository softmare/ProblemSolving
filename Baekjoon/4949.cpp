#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

bool isWellPaired(char* sentance)
{
    vector<char> braceStack;
    const map<char, char> rightPair =
    {
        {')' , '('},
        {']' , '['}
    };
    const char EOL = '.';
    bool pairingSuccess = true;
    for(int i=0; sentance[i] != EOL; ++i)
    {
        switch(const char &c = sentance[i])
        {
            case '(': case '[':
            braceStack.push_back(c);
            break;
            case ')': case ']':
            if(!braceStack.empty() && braceStack.back() == rightPair.at(c))
            {
                cout << "back : " + braceStack.back() << " rigthpair.at(c) : " + rightPair.at(c) << endl;
                braceStack.pop_back();
            }
            else
            {
                pairingSuccess = false;
            }
            break;
            default:
            break;
        }
        if(!pairingSuccess)
        {
            break;
        }
    }
    if(!braceStack.empty())
    {
        pairingSuccess = false;
    }
    return true;
}

int main()
{
    const int MAX_SENTANCE_LENGTH = 101;
    char input[MAX_SENTANCE_LENGTH];
    while(!cin.getline(input, MAX_SENTANCE_LENGTH).eof())
    {
        if(isWellPaired(input))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}
