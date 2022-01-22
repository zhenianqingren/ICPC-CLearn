#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
typedef list<int> lint;
int value[] = {2, 4, 5, 7, 9, 12};
void print(lint &l)
{
    lint::iterator pit;
    for (pit = l.begin(); pit != l.end(); pit++)
        cout << (*pit) << " ";
    cout << endl;
    /*ostream_iterator<int> output(cout," "); 
 copy(l.begin(),l.end(),output); 
- 10 -
 */
}
int main()
{
    // list<type>l
    // list<type>l(begin,end)
    // list<type>l(n,elem)
    // list<type>l(l_)
    // assign(begin,end)
    // assign(n,elem)
    // swap(l)
    // list operator(const list&l)
    // empty()
    // size()
    // resize(int len)
    // resize(int len , elem)
    // push_back(elem)
    // pop_back()
    // push_front(elem)
    // pop_front()
    // insert(const_iterator pos,elem)
    // insert(const_iterator pos, int n,elem)
    // erase(const_iterator pos) (return next pos)
    // erase(const_iterator start, const_iterator end)
    // clear()
    // remove(elem)
    // front() return the first elem
    // back() return the last elem
    // reverse()
    // sort() can use predicate
    lint firstl, secondl;
    firstl.push_front(1);
    firstl.push_front(2);
    firstl.push_back(4);
    firstl.push_back(3);
    cout << "The first list contains: ";
    print(firstl);
    firstl.sort();
    cout << "After sort the first list: ";
    print(firstl);

    secondl.insert(secondl.begin(), value, value + 6);
    cout << "The second list contains: ";
    print(secondl);
    firstl.splice(firstl.end(), secondl);
    cout << "After splice the first list contians: ";
    print(firstl);
    firstl.sort([](int x, int y) -> bool
                { return x > y; });
    cout << "After sort with compare function: ";
    print(firstl);

    firstl.unique();
    cout << "After unique the first list: ";
    print(firstl);

    firstl.remove(9);
    cout << "After remove value 9 : ";
    print(firstl);

    secondl.insert(secondl.end(), value, value + 5);
    firstl.swap(secondl);
    cout << "After swap with the second list: ";
    print(firstl);

    getchar();
    return 0;
}