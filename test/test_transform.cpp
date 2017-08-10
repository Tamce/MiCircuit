#define DEBUG
#include "../src/include/transform.h"
#include <cstdio>
using namespace std;
using namespace tmc::mcc;
void print(const Transform &t)
{
    printf("(%d;%d,%d,%d)", t.d, t.p[0], t.p[1], t.p[2]);
}
int main()
{
    // passed
    // Transform t;
    // Transform t(Transform::Position({1,1,1}));
    // Transform t(Transform::Position({1,1,1}), Transform::Direction::up);
    print(t);
    return 0;
}