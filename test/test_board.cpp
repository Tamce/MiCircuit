#define DEBUG
#include "../src/board.cpp"
#include "../src/unit.cpp"
#include <cstdio>
using namespace std;
using namespace tmc::mcc;
int main()
{
    Board b(Size({2, 2, 3}));
    b.resize(Size({3, 3, 2}));

    //********** Test: Board::at & Board::resize
    for (auto i = 0u; i < b.size()[0]; ++i)
        for (auto j = 0u; j < b.size()[1]; ++j)
            for (auto k = 0u; k < b.size()[2]; ++k)
            {
                printf("(%d,%d,%d):", i, j, k);
                b.at({i, j, k}).print();
                printf("\n");
            }
    //*/

    /********* Test: Board::size
    auto size = b.size();
    printf("dimention: %d\n", size.size());
    for (int i = 0; i < DEMENTION; ++i)
        printf("%d,", size[i]);
    */

    // b.at({1,0,0}).print();

    return 0;
}