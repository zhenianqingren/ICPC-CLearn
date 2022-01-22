#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <time.h>
#include "travel.h"
using namespace std;
void print(int i)
{
    cout << i << " ";
}
int trans(int i)
{
    return i + 10;
}

class person
{
public:
    string name;
    int age;
    person(string n, int a)
    {
        name = n;
        age = a;
    }
    bool operator==(const person &p)
    {
        if (name == p.name && age == p.age)
            return true;
        return false;
    }
};

bool AgeCheck(const person &p)
{
    return p.age > 15;
}

bool TestJudge(int i)
{
    return i > 5;
}
int main()
{
    // for_each() travel container
    // transform() move container
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(i);
    for_each(v1.begin(), v1.end(), print);
    vector<int> v2;
    cout << '\n';
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), trans);
    for_each(v2.begin(), v2.end(), print);
    transform(v1.begin(), v1.end(), v1.begin(), trans);
    cout << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << "\n \n \n";

    // find()  search element
    // find_if() search element according to conditions
    // adjacent_find() find adjacent duplicate elements
    // binary_search()
    // count() the number of elements
    // count_if() the number of elements according to conditions

    vector<person> p;
    person p1("aaa", 10);
    person p2("bbb", 20);
    person p3("ccc", 30);
    person p4("ddd", 40);
    person test("bbb", 20);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    vector<person>::iterator ite = find(p.begin(), p.end(), test);
    cout << (*ite).name << "  " << (*ite).age << endl;
    ite = find_if(p.begin(), p.end(), AgeCheck);
    cout << (*ite).name << "  " << (*ite).age << endl;

    cout << "\n \n \n";

    vector<int> v3;
    v3.push_back(0);
    v3.push_back(1);
    v3.push_back(0);
    v3.push_back(3);
    v3.push_back(3);
    vector<int>::iterator pos = adjacent_find(v3.begin(), v3.end());
    cout << *pos << endl;
    sort(v3.begin(), v3.end());
    bool temp = binary_search(v3.begin(), v3.end(), 1);
    cout << temp << endl;
    cout << count(v3.begin(), v3.end(), 3) << endl;
    cout << count_if(p.begin(), p.end(), AgeCheck);

    //sort
    //random_shuffle
    //merge   elements should be in order
    //reverse

    cout << "\n \n \n";

    vector<int> v4;
    for (int i = 0; i < 10; i++)
        v4.push_back(i);
    srand((unsigned int)time(NULL));
    random_shuffle(v4.begin(), v4.end());
    trav(v4);
    sort(v4.begin(), v4.end());
    vector<int> v5;
    for (int i = 0; i < 10; i++)
        v5.push_back(i);
    vector<int> v6;
    v6.resize(v4.size() + v5.size());
    merge(v4.begin(), v4.end(), v5.begin(), v5.end(), v6.begin());
    trav(v6);
    reverse(v6.begin(), v6.end());
    trav(v6);

    cout << "\n \n \n";
    //copy
    //replace
    //replace_if
    //swap

    vector<int> v7(v6.size());
    copy(v6.begin(), v6.end(), v7.begin());
    trav(v7);

    replace(v7.begin(), v7.end(), 5, -1);
    trav(v7);

    replace_if(v7.begin(), v7.end(), TestJudge, 100);
    trav(v7);

    swap(v6, v7);
    trav(v7);
    cout << "\n \n \n";

    //accumulate   calculate total sum
    //fill
    int total = accumulate(v6.begin(), v6.end(), 0);
    cout << total << endl;

    fill(v6.begin(), v6.end(), 2);
    total = accumulate(v6.begin(), v6.end(), 0);
    cout << total << endl;


    getchar();
    return 0;
}