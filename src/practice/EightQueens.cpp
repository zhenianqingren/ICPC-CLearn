#include <iostream>
using namespace std;

bool line[8] = {true, true, true, true, true, true, true, true};
bool dia1[15] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
bool dia2[15] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
char checkerBoard[8][8];
int count = 0;

int l[8] = {0};

void Print1()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << checkerBoard[i][j] << " ";
        cout << endl;
    }
    cout << "\n"
         << "----------------------------------"
         << "\n";
}

void EightQueens(int r)
{
    if (r == 8)
    {
        count++;
        Print1();
        return;
    }

    for (int l = 0; l < 8; l++)
        if (line[l] && dia1[r - l + 7] && dia2[r + l])
        {
            checkerBoard[r][l] = '1';
            line[l] = dia1[r - l + 7] = dia2[r + l] = false;
            EightQueens(r + 1);
            checkerBoard[r][l] = '*';
            line[l] = dia1[r - l + 7] = dia2[r + l] = true;
        }
}

bool check(int r)
{
    for (int i = 0; i < r; i++)
        if (l[i] == l[r] || i - l[i] == r - l[r] || i + l[i] == r + l[r])
            return false;
    return true;
}

void Print2()
{
    count++;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < l[i]; j++)
            cout << '*' << " ";
        cout << '1' << " ";
        for (int j = l[i] + 1; j < 8; j++)
            cout << '*' << " ";
        cout << endl;
    }
    cout << "\n"
         << "----------------------------------"
         << "\n";
}

void eightQueens()
{
    int r = 0;
    l[r] = 0;
    while (r >= 0)
    {
        if (r < 8 && l[r] < 8)
        {
            if (check(r))
            {

                r++;
                l[r] = 0;
            }
            else
                l[r]++;
        }
        else
        {
            if (r >= 8)
                Print2();
            r--;
            l[r]++;
        }
    }
}

int main()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            checkerBoard[i][j] = '*';

    // EightQueens(0);
    eightQueens();

    cout << count;
    getchar();
    return 0;
}