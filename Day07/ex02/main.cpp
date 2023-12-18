#include "Array.hpp"

int main() {
    Array<std::string> test(4);
    test[1] = "salut";
    test[2] = "hi";
    size_t i = test.getSize();
    std::cout << i << std::endl;
    Array<std::string> test2;
    test2 = test;

    std::cout << test[2] << std::endl;
    

    return 0;
}