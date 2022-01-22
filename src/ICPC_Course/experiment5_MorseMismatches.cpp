#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<char, string> MorseCode;
map<string, string> Dict;
vector<string> Words;
vector<string> Text;

void Input();
void Translate();
void OutPut();

int main()
{
    Input();
    Translate();
    for (map<string, string>::iterator ite = Dict.begin(); ite != Dict.end(); ite++)
        cout << ite->first << "   " << ite->second << endl;
    for (size_t i = 0; i < Text.size(); i++)
        cout << Text[i] << endl;
    OutPut();
    cout << endl;
    system("pause");
    return 0;
}

void Input()
{
    char ch;
    string Temp;
    while (cin >> ch)
    {
        if (ch == '*')
        {
            Temp.clear();
            break;
        }
        cin >> Temp;
        MorseCode[ch] = Temp;
        Temp.clear();
    }
    while (true)
    {
        cin >> Temp;
        if (Temp[0] == '*')
        {
            Temp.clear();
            break;
        }
        Words.push_back(Temp);
        Temp.clear();
    }
    while (true)
    {
        cin >> Temp;
        if (Temp[0] == '*')
        {
            Temp.clear();
            break;
        }
        Text.push_back(Temp);
        Temp.clear();
    }
    sort(Words.begin(), Words.end(), [](string s1, string s2) -> bool
         { return s1.size() < s2.size(); });
}

void Translate()
{
    for (size_t i = 0; i < Words.size(); i++)
    {
        Dict[Words[i]] = "";
        for (size_t j = 0; j < Words[i].size(); j++)
            Dict[Words[i]].insert(Dict[Words[i]].size(), MorseCode[Words[i][j]]);
    }
}

void OutPut()
{
    pair<string, string> *Search = NULL;
    int num;
    string output = "";
    for (size_t i = 0; i < Text.size(); i++)
    {
        Search = NULL;
        num=0;
        for_each(Dict.begin(), Dict.end(), [&](pair<string, string> P)
                 {
                     if (P.second == Text[i])
                     {
                         num++;
                         if (Search == NULL || P.first.size() < Search->first.size())
                             Search = new pair<string, string>(P.first, P.second);
                     };
                 });

        if (Search)
        {
            output.assign(Search->first);
            if (num > 1)
                output.push_back('!');
            cout << output << endl;
        }
        else
        {
            output.assign(Text[i]);
            while (true)
            {
                output.pop_back();
                for (map<string, string>::iterator ite = Dict.begin(); ite != Dict.end(); ite++)
                {
                    if (ite->second.size() == output.size())
                    {
                        if (ite->second == output)
                        {
                            Search = new pair<string, string>(ite->first, ite->second);
                            break;
                        }
                    }
                    else if (ite->second.size() > output.size())
                        if (ite->second.substr(0, output.size()) == output)
                        {
                            Search = new pair<string, string>(ite->first, ite->second);
                            break;
                        }
                }
                if (Search != NULL)
                {
                    cout << Search->first << "?\n";
                    break;
                }
            }
        }
    }
}