#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
void foo()
{
    cout << "#";
    this_thread::sleep_for(chrono::seconds(1) + chrono::milliseconds(500));
    cout << ".";
}

int main()
{
    while (true)
    {
        auto start = chrono::steady_clock::now();
        foo();
        // If now() > start+duration, do not sleep()
        this_thread::sleep_until(start + chrono::seconds(1));
    }
    return 0;
}

