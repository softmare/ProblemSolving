#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Point
{
    int x;
    int y;
    
    string ToString()
    {
        return to_string(x) + ' ' + to_string(y);
    }
};

bool secondIsBigger(Point first, Point second)
{
    if(second.y > first.y) return true;
    else if(second.y < first.y) return false;
    else
    {
        if(second.x > first.x) return true;
        else return false;
    }
}

int main()
{
    int n; cin >> n;
    vector<Point> Points;
    for(int i = 0 ; i < n ; ++i)
    {
        int x, y; cin >> x >> y;
        Points.push_back(Point{x, y});
    }
    sort(Points.begin(), Points.end(), secondIsBigger);
    for(auto point : Points)
    {
        cout << point.ToString() << '\n';
    }
    return 0;
}