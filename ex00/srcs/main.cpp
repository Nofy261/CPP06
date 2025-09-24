/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:34 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/24 15:08:07 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>


int main(int argc, char **argv)
{
    // A verifier ici si chaine vide ? ./convert " "
    if (argc == 2)
    {
        ScalarConverter::convert(argv[1]); 
    }
    else
        std::cout << "Invalid number of argument." << std::endl;
    return (0);
}


