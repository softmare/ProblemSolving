#include<bits/stdc++.h>

using namespace std;

int table[100][100][100];
int M, N, H;

typedef struct _msg
{
    int m, n, h;
    int time;
    _msg(const int h,const int n,const int m,const int time) : m(m), n(n), h(h), time(time) {}
} msg;

queue<msg> q;
int last_time = 0;

bool isHereUnseasonedTomato(const msg &message)
{
    const int &h = message.h;
    const int &n = message.n;
    const int &m = message.m;

    if(h >= H || m >= M || n >= N || h < 0 || m < 0 || n < 0 || table[h][n][m] != 0)
    {
        // cout << "false : " <<  h << ' ' << n << ' ' << m << ' ' << endl;
        return false;
    }
        // cout << "true : " <<  h << ' ' << n << ' ' << m << ' ' << endl;
    return true;
}

void queuing(const msg &message)
{
    const int h = message.h;
    const int n = message.n;
    const int m = message.m;
    q.push(msg(h,n,m+1, message.time+1));
    q.push(msg(h,n+1,m, message.time+1));
    q.push(msg(h+1,n,m, message.time+1));
    q.push(msg(h,n,m-1, message.time+1));
    q.push(msg(h,n-1,m, message.time+1));
    q.push(msg(h-1,n,m, message.time+1));
}

void execute(const msg &message)
{
    if(!isHereUnseasonedTomato(message)) return;
    const int h = message.h;
    const int n = message.n;
    const int m = message.m;
        // cout << "executing : " <<  h << ' ' << n << ' ' << m << ' ' << message.time << ' ' << endl;
    table[h][n][m] = 1;
    last_time = message.time;
    queuing(message);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> M >> N >> H;
    for(int h=0; h<H; ++h)
    for(int n=0; n<N; ++n)
    for(int m=0; m<M; ++m)
    {
        cin >> table[h][n][m];
        if(table[h][n][m] == 1)
        {
            queuing(msg(h,n,m,0));
        }
    }
    while(!q.empty())
    {
        msg &message = q.front();
    const int h = message.h;
    const int n = message.n;
    const int m = message.m;
        execute(q.front());
        // cout << h << ' ' << n << ' ' << m << ' ' << message.time << endl;
        q.pop();
    }

    // check all tomatos are seasoned
    bool allSeasoned = true;
    for(int h=0; h<H; ++h)
    for(int n=0; n<N; ++n)
    for(int m=0; m<M; ++m)
    {
        if(table[h][n][m] == 0)
            allSeasoned = false;
    }
    if(allSeasoned)
    {
        cout << last_time;
    }else{
        cout << "-1";
    }
    return 0;
}