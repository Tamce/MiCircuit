#define DEBUG
#include <cstdio>
#include "../src/unit.cpp"
using namespace std;
using namespace tmc::mcc;

int main()
{
    /* Passed */
    // Unit u;
    // Unit u(UnitType::Null, Transform::Position({1,1,1}));
    Unit u(UnitType::Error, Transform::Position({1,1,1}));
    u.print();
    printf("\n%d,%d", u.is(UnitType::Null), u.is(UnitType::Error));
    return 0;
}