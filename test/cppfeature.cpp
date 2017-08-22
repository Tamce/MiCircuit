#include <iostream>
#include <functional>
using namespace std;
class A
{
public:
    void f() {}
};

int main()
{
    A a;
    function<void()> f;
    f = bind(&A::f, &a);
    f();
    return 0;
}

