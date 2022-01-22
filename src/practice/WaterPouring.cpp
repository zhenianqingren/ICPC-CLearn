#include <iostream>
using namespace std;

int MAXA = 4;
int MAXB = 7;
int N;

bool visited[500][500];

void DFS(int A, int B, bool &Find)
{
    if (Find)
        return;
    cout << "A->" << A << "----B->" << B << endl;
    visited[A][B] = false;
    if (A == N || B == N || A + B == N)
    {
        Find = true;
        return;
    }

    if (A != 0 && visited[0][B])
        DFS(0, B, Find);
    if (B != 0 && visited[A][0])
        DFS(A, 0, Find);
    if (A != MAXA && visited[MAXA][B])
        DFS(MAXA, B, Find);
    if (B != MAXB && visited[A][MAXB])
        DFS(A, MAXB, Find);
    if (A != MAXA && B != 0 && visited[A + B > MAXA ? MAXA : A + B][A + B > MAXA ? A + B - MAXA : 0]) //B->A
        DFS(A + B > MAXA ? MAXA : A + B, A + B > MAXA ? A + B - MAXA : 0, Find);
    if (A != 0 && B != MAXB && visited[A + B > MAXB ? A + B - MAXB : 0][A + B > MAXB ? MAXB : A + B]) //A->B
        DFS(A + B > MAXB ? A + B - MAXB : 0, A + B > MAXB ? MAXB : A + B, Find);
}

int main()
{

    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            visited[i][j] = true;
    bool isFind = false;
    N=5;
    DFS(0, 0, isFind);
    getchar();
    return 0;
}