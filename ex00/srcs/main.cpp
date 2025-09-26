/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:34 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/26 13:02:40 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string arg = argv[1];
        if (arg.empty())
        {
            std::cout << "Value is empty." << std::endl;
            return (1);
        }
        ScalarConverter::convert(argv[1]); 
    }
    else
        std::cout << "Invalid number of argument." << std::endl;
    return (0);
}
