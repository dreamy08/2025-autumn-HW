#include <iostream>
#include "string.hpp"

int main() {
    const SliceString hello("hello");

    String hell = hello[0][4];   // "hell"
    String ell  = hello[1][4];   // "ell"
    String empty = hello[2][2];  // ""

    std::cout << hell << "\n";
    std::cout << ell << "\n";
    std::cout << empty << "\n";

    return 0;
}
