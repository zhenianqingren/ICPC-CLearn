#include <iostream>
using namespace std;
// defination:
// Overloaded () classes whose objects are called function objects

// use:
// when used, funtion object is just like common function
// funtion object can possess own status
// it can be passed as parameter
class MyAdd
{
public:
    int operator()(int a,int b)
    {
        return a+b;
    }
};
int test(MyAdd Add,int a,int b)
{
    return Add(a,b);
}
int main()
{
    cout<<MyAdd()(10,10)<<endl;
    cout<<test(MyAdd(),10,10);
    cout << endl;
    system("pause");
    return 0;
}