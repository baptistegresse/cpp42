#include <cstdlib>
#include <iostream>

template <typename T>
void iter(T *array, size_t len, void f(const T &item)) {
    for (size_t i = 0; i < len; i++) {
        f(array[i]);
    }
}

template <typename T>
static void printItem(T const & item) {
	std::cout << item << std::endl;
}

int main() {
	std::cout << "--------- INT ---------" << std::endl;
	int arr[5] = {2, 5, 78, 24, -12};
	iter(arr, 5, printItem);

	std::cout << "--------- STRING ---------" << std::endl;
	std::string arrStr[5] = {"2", "string", "template", "test\n", "%^*&"};
	iter(arrStr, 5, printItem);
}