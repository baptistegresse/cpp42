#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstring>

class ScalarConverter {
public:
    static void convert(const std::string &literal);
    
    class nonDisplayable : public std::exception {
        public:
            const char* what() const throw();
    };

    class overFlow : public std::exception {
        public:
            const char* what() const throw();
    };
private:
    ScalarConverter();
};
 