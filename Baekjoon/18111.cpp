#include<iostream>

using namespace std;

class Map
{
    private::
    const unsigned int map[500][500];
    const unsigned int N, M, BlockCountWhenBegin;

    public::
    Map(unsigned int N, unsigned int M, unsigned int BlockCountWhenBegin )
    {
        this.N = N;
        this.M = M;
        this.BlockCountWhenBegin = BlockCountWhenBegin;
    }

    unsigned int CalcTimeCost(unsigned int targetLevel, unsigned int currentLevel)
    {
        unsigned int timeCost;
        if(targetLevel < currentLevel)
            timeCost = (currentLevel - targetLevel) * 2;
        else
            timeCost = (targetLevel - currentLevel);
        return timeCost;
    }

    int CalcBlockVariance(unsigned int targetLevel, unsigned int currentLevel)
    {
        return targetLevel - currentLevel;
    }

    bool IsPossible(int totalBlockCost)
    {
        return blockCountWhenBegin >= totalBlockCost;
    }
};

int map[500][500];
int N, M, BlockCountWhenBegin;


int main()
{
    cin >> N >> M >> BlockCountWhenBegin;
    return 0;
}