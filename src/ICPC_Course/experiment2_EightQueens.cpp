#include <iostream>
#include <memory.h>
#include<vector>
using namespace std;
const int N = 8;
int count = 0;
void input();
void Print(int locate[]);
void _Queens(int level, int locate[], int line[], int diagonal[], int angle[]);

class Solution {
public:
    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }

    int solve(int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            return 1;
        } else {
            int count = 0;
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions-position;
                count += solve(n, row + 1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
            }
            return count;
        }
    }
};


int main(int argc, char *argv[])
{
    cout<<Solution().totalNQueens(16);
    // input();
    cout << endl;
    system("pause");
    return EXIT_SUCCESS;
}

void input()
{
    int locate[N];
    int line[N];
    int diagonal[2 * N - 1];
    int angle[2 * N - 1];
    memset(locate, 0, sizeof(locate));
    memset(line, 0, sizeof(line));
    memset(diagonal, 0, sizeof(diagonal));
    memset(angle, 0, sizeof(angle));

    _Queens(0, locate, line, diagonal, angle);
    cout << '\n'
         << count;
}

void Print(int locate[])
{
    cout << "----------------------------\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (locate[i] == j)
                cout << "* ";
            else
                cout << "0 ";
        }
        cout << '\n';
    }
    cout << "\n----------------------------";
    count++;
}

void _Queens(int level, int locate[], int line[], int diagonal[], int angle[])
{
    if (level >= N)
        Print(locate);
    for (int pos = 0; pos < N; pos++)
    {
        if (!line[pos] && !diagonal[pos + level] && !angle[pos - level + N - 1])
        {
            locate[level] = pos;
            line[pos] = diagonal[pos + level] = angle[pos - level + N - 1] = 1;
            _Queens(level + 1, locate, line, diagonal, angle);
            line[pos] = diagonal[pos + level] = angle[pos - level + N - 1] = 0;
            locate[level] = 0;
        }
    }
}


