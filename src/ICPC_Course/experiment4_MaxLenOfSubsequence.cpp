#include <iostream>
#include <string>
#include <memory.h>
using namespace std;

struct status
{
    int len;
    string sequence;
    status() {}
    status(int l) : len(l), sequence("") {}
    status(int l, char ch) : len(l), sequence("") { sequence.push_back(ch); }
    status(int l, string s) : len(l), sequence(s) {}
    status(status *Copy) : len(Copy->len), sequence(Copy->sequence) {}
};

status MaxLenOfSubsequence(string s1, string s2);

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    status result = MaxLenOfSubsequence(s1, s2);
    cout << result.len << "  " << result.sequence << endl;
    system("pause");
    return 0;
}

status MaxLenOfSubsequence(string s1, string s2)
{
    status **dp = new status *[int(s2.size())];
    for (size_t i = 0; i < s2.size(); i++)
        dp[i] = new status[int(s1.size())];

    for (size_t i = 0; i < s2.size(); i++)
        dp[i][0] = s2.substr(0,i+1).find(s1[0])!=s2.npos ? status(1, s1[0]) : status(0);

    for (size_t i = 0; i < s1.size(); i++)
        dp[0][i] = s1.substr(0,i+1).find(s2[0])!=s1.npos ? status(1, s2[0]) : status(0);

    for (size_t i = 1; i < s2.size(); i++)
        for (size_t j = 1; j < s1.size(); j++)
            if (s1[j] == s2[i])
                dp[i][j] = status(1 + dp[i - 1][j - 1].len, dp[i - 1][j - 1].sequence + s2[i]);
            else
                dp[i][j] = dp[i - 1][j].len > dp[i][j - 1].len ? status(&dp[i - 1][j]) : status(&dp[i][j - 1]);

    return dp[int(s2.size()) - 1][int(s1.size()) - 1];
}

// 1a345
// 4a55