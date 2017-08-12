#define DEBUG
#include "../src/boardIterator.cpp"
#include "../src/board.cpp"
#include "../src/unit.cpp"
#include <cstdio>
using namespace std;
using namespace tmc::mcc;

int main()
{
    Board board({3, 3, 2});
    BoardIterator it(board, board.at({0,1,1}));
    (*it).print();
    it.move(Transform::Position({2,1,0}));
    (*it).print();
}