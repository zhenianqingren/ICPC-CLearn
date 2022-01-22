#include <iostream>
#include <memory.h>
using namespace std;
const int MAXA = 4;
const int MAXB = 7;
int N;
bool visited[512][512];
void DFS(int A, int B, bool &Find);

int main()
{
    for (int i = 0; i < 512; i++)
        memset(visited[i], false, sizeof(visited[0]));
    bool Find = false;
    N=5;
    DFS(0, 0, Find);
    cout << endl;
    system("pause");
    return EXIT_SUCCESS;
}

void DFS(int A, int B, bool &Find)
{
    if (Find)
        return;
    cout << "A->" << A << "----B->" << B << endl;
    visited[A][B] = true;
    if (A == N || B == N || A + B == N)
    {
        Find = true;
        return;
    }
    if (A && !visited[0][B])
        DFS(0, B, Find);
    if (B && !visited[0][B])
        DFS(A, 0, Find);
    if (A != MAXA && !visited[A][B])
        DFS(MAXA, B, Find);
    if (B != MAXB && !visited[A][MAXB])
        DFS(A, MAXB, Find);
    if (B && A != MAXA && !visited[A + B > MAXA ? MAXA : A + B][A + B > MAXA ? A + B - MAXA : 0])
        DFS(A + B > MAXA ? MAXA : A + B, A + B > MAXA ? A + B - MAXA : 0, Find);
    if (A && B != MAXB && !visited[A + B > MAXB ? A + B - MAXB : 0][A + B > MAXB ? MAXB : A + B])
        DFS(A + B > MAXB ? A + B - MAXB : 0, A + B > MAXB ? MAXB : A + B, Find);
}