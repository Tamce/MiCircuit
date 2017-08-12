#include <iostream>
#include <unordered_map>
enum E {a = 0, b = 1};
E operator!(E e)
{
    return E(e ^ 1);
}

int main()
{
    std::unordered_map<E, int, std::hash<int>, std::equal_to<int>, std::allocator<std::pair<const int, int>>> m;
    return 0;
}

