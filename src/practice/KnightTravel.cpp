#include <iostream>
using namespace std;

struct coordinate
{
    int x;
    int y;
};

bool mark[8][8];

namespace This
{
    int next[8][2] = {
        {2, 1},
        {-2, -1},
        {2, -1},
        {-2, 1},
        {-1, -2},
        {1, -2},
        {1, 2},
        {-1, 2}};
    int count = 0;
}

bool isLegal(int x, int y)
{
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && mark[x][y])
        return true;
    else
        return false;
}

void dfs(coordinate N)
{
    cout << "( " << N.x << " , " << N.y << " ) " << endl;
    mark[N.x][N.y] = false;
    This::count++;

    for (int i = 0; i < 8; i++)
    {
        int X = N.x + This::next[i][0];
        int Y = N.y + This::next[i][1];
        if (isLegal(X, Y))
            dfs(coordinate{X, Y});
    }
}

int main()
{

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            mark[i][j] = true;

    dfs(coordinate{5, 9});
    cout<<This::count<<endl;

    getchar();
    return 0;
}
