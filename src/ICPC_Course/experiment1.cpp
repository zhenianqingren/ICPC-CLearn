#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
void Print(vector<int> v)
{
    for (vector<int>::iterator ite = v.begin(); ite != v.end(); ite++)
        cout << *ite << " ";
    cout << '\n';
}
void Print(list<int> l)
{
    for (list<int>::iterator ite = l.begin(); ite != l.end(); ite++)
        cout << *ite << " ";
    cout << '\n';
}
int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(rand());

    cout << "init vector:   ";
    Print(v);

    cout << "After insert:   ";
    v.insert(v.begin(), rand());
    Print(v);

    int rand_num = v[4];
    cout << "find randint:  "
         << rand_num << '\n';
    vector<int>::iterator ite = find(v.begin(), v.end(), rand_num);
    if (ite == v.end())
    {
        cout << "Not Found\n";
        v.insert(v.end(), rand_num);
    }
    else
        cout << "NO." << (int)(ite - v.begin()) + 1 << ":  " << *ite << '\n';

    cout << "After sort:   ";
    sort(v.begin(), v.end());
    Print(v);

    cout << "Delete the last one:   ";
    v.pop_back();
    Print(v);
    v.clear();
    cout << "\n\n\n";
    list<int> l;
    for (int i = 0; i < 10; i++)
        l.push_back(rand());
    cout << "init list:   ";
    Print(l);

    cout << "After insert:   ";
    l.insert(l.begin(), rand());
    Print(l);

    rand_num = rand();
    cout << "find randint:  " << rand_num << '\n';
    list<int>::iterator ite_l = find(l.begin(), l.end(), rand_num);
    if (ite_l == l.end())
    {
        cout << "Not Found\n";
        l.insert(l.end(), rand_num);
    }
    else
        cout << "Found:  " << *ite_l << '\n';

    cout << "After sort:   ";
    l.sort();
    Print(l);

    cout << "Delete the last one:  ";
    l.pop_back();

    Print(l);
    l.clear();
    cout << "\n\n\n";

    for (int i = 0; i < 10; i++)
        v.push_back(rand());
    cout << "init:   ";
    Print(v);
    cout << "After up sort:   ";
    sort(v.begin(), v.end());
    Print(v);
    cout << "After down sort:   ";
    sort(v.begin(), v.end(), [](int x, int y) -> bool
         { return x > y; });
    Print(v);
    int elem;
    cout << "Please input element you want to find:  ";
    cin >> elem;
    vector<int>::iterator ite_v = find(v.begin(), v.end(), elem);
    if (ite_v == v.end())
        cout << "Not Found\n";
    else
        cout << "NO." << (int)(ite_v - v.begin()) + 1 << ":  " << *ite_v << '\n';

    cout << "max element:   " << *max_element(v.begin(),v.end()) << '\n';
    cout << "min element:   " << *min_element(v.begin(),v.end()) << '\n';
    
    system("pause");
    return 0;
}