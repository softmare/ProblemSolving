#include<bits/stdc++.h>
using namespace std;

typedef struct _msg
{
    short idx, from;
}msg;
short link[10000];
char operate[10000];
queue<msg> q;

short D(short val)
{
    return (val*2)%10000;
}
short S(short val)
{
    return (val+9999) % 10000;
}
short L(short val)
{
    char leftest = val / 1000;
    return (val%1000)*10 + leftest;
}
short R(short val)
{
    char rightest = val % 10;
    return (val/10) + 1000 * rightest;
}

void executeOneStep()
{
    cout.flush();
    msg frontMessage = q.front();
    q.pop();
    short from = frontMessage.from;
    short idx = frontMessage.idx;
    if(link[idx] != -1) return;
    link[idx] = from;
    short res = D(idx);
    q.push(msg{ .idx = res, .from = idx,});
    
    operate[res] = operate[res] ? operate[res] : 'D';
    // cout << "from " << from << " to " << idx << " and D(idx) : " << q.back().idx << endl;
    res = S(idx);
    q.push(msg{.idx = res, .from = idx});
    operate[res] = operate[res] ? operate[res] : 'S';
    // cout << "from " << from << " to " << idx << " and S(idx) : " << q.back().idx << endl;
    res = L(idx);
    q.push(msg{ .idx = res, .from = idx,});
    operate[res] = operate[res] ? operate[res] : 'L';
    // cout << "from " << from << " to " << idx << " and L(idx) : " << q.back().idx << endl;
    res = R(idx);
    q.push(msg{ .idx = res, .from = idx,});
    operate[res] = operate[res] ? operate[res] : 'R';
    // cout << "from " << from << " to " << idx << " and R(idx) : " << q.back().idx << endl;
}

string trackOfSrc(short src, short dst)
{
    cout.flush();
    short cur = dst;
    string res_rev;
    while(true)
    {
        // cout << "cur : "  << cur ;
        if(cur == src) break;
        res_rev += operate[cur];
        // cout << "op : " << operate[cur] << endl;
        cur = link[cur];
    }
    return res_rev;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        for_each(link, link+10000, [](short &item){item = -1;});
        for_each(operate, operate+10000, [](char &c){c = '\0';});
        short startVal, destVal;
        q = queue<msg>();
        cin >> startVal >> destVal;
        q.push(msg{.idx = startVal, .from = -1});
        while(link[destVal] == -1)
        {
            executeOneStep();
        }    
        string res_rev = trackOfSrc(startVal, destVal);
        // cout << "res : ";
        for_each(res_rev.rbegin(),res_rev.rend(), [](char c){cout << c;});
        cout << '\n';
        // for_each(operate, operate + 100, [](char c){if(c) cout << c; else cout << ' ';} );
        // cout << '\n';
        // for_each(link, link + 100, [](short c){if(c) cout << c; else cout << ' ';} );
        // cout << '\n';
    }
    return 0;
}