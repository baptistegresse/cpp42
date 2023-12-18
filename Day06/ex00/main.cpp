/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:25:07 by ubuntu            #+#    #+#             */
/*   Updated: 2023/12/18 14:16:41 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <string representation>" << std::endl;
        return (1);
    }
    
    if (argv[1][0] == '0' && argv[1][1] == '\0')
    {
        std::cerr << "0 can't be convert" << std::endl;
        return (1);
    }

    ScalarConverter::convert(argv[1]);
    return (0);
}