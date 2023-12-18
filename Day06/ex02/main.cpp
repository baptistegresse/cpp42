#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include <iostream>


Base * generate() {
    switch(rand() % 3) {
        case 0:
            return new A();
        break;
        case 1:
            return new B();
        break;
        case 2:
            return new C();
        break;
        default:
            return NULL;
    };
}

void identify(Base* p) {
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "unknow" << std::endl;
}

void	identify( Base& p )
{
	Base result;

	try
	{
		result = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...) { }
	try
	{
		result = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (...) { }
	try
	{
		result = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (...) { }
}


int main() {
    srand(time(NULL));

    Base *ptr = generate();
    if (!ptr)
        return (1);

    identify(ptr);
    identify(*ptr);

    delete ptr;
    return (0);
}

