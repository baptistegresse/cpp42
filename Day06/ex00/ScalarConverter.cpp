/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:15:21 by ubuntu            #+#    #+#             */
/*   Updated: 2023/12/18 14:13:45 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <limits>

const char *ScalarConverter::nonDisplayable::what() const throw()
{
    return "Non displayable";
}

const char *ScalarConverter::overFlow::what() const throw()
{
    return "impossible";
}

static bool isPrintable(int number)
{
    return number >= 32 && number <= 126;
}

void  ScalarConverter::convert(const std::string &literal)
{

    if (literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return ;
    }

    double number;
    
    number = std::strtod(literal.c_str(), NULL);
    if (!number)
        return ;

    try
    {
        if (!isPrintable(number))
            throw ScalarConverter::nonDisplayable();
        std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;     
    }
    catch (const std::exception &error)
    {
        std::cerr << "char: " << error.what() << std::endl;
    }

    try
    {
        if (number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
            throw ScalarConverter::overFlow();
        std::cout << "int: " << static_cast<int>(number) << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cerr << "int: " << error.what() << std::endl;
    }

    try
    {
        if (number > std::numeric_limits<float>::max() || number < std::numeric_limits<float>::min())
            throw ScalarConverter::overFlow();
        std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cerr << "float: " << error.what() << std::endl;
    }

    try
    {
        if (number > std::numeric_limits<double>::max() || number < std::numeric_limits<double>::min())
            throw ScalarConverter::overFlow();
        std::cout << "double: " << static_cast<double>(number) << std::endl;
    }
    catch(const std::exception& error)
    {
        std::cerr << "double: " << error.what() << std::endl;
    }

    
}
