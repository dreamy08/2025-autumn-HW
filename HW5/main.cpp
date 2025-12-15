#include "array.hpp"

int main() {
    // Пример для int
    int a[] = {5, 2, 9, 1, 7};
    int b[] = {3, 8, 4, 6, 0};

    Array<int, 5> A(a);
    Array<int, 5> B(b);

    std::cout << "A: "; A.show();
    std::cout << "B: "; B.show();

    // B станет покомпонентным минимумом A и B
    A.minimum(B);

    std::cout << "min(A, B) stored in B: ";
    B.show();

    return 0;
}
