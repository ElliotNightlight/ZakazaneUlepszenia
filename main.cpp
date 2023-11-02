#include <iostream>
#include "zakazana.hpp"

int main() {

    for(const Int32 i : Range(17, 100))
        std::cout << i << ' ';
    std::cout << '\n';

    for(const Int32 i : RangeReversed(23, 30))
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
