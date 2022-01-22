#include <iostream>
using namespace std;

string s1="pearabcgiuopadfasdf";
string s2="peachauythnbmklttc";

int main()
{
    int x = s1.size();
    int y = s2.size();
    int **dp = new int *[x];
    for (int i = 0; i < x; i++)
        dp[i] = new int[y];

    for (int i = 0; i < y; i++)
        dp[0][i] = (s1[0] == s2[0] ? 1 : 0);
    for (int i = 1; i < x; i++)
        dp[i][0] = (s1[0] == s2[0] ? 1 : 0);

    for (int i = 1; i < x; i++)
        for (int j = 1; j < y; j++)
            if (s1[i] == s2[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    cout << dp[x - 1][y - 1] << endl;
    getchar();
    return 0;
}