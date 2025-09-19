/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:30 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/19 12:28:53 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

// classe non instanciable
class ScalarConverter
{
    public :
        ~ScalarConverter();    

        static void convert(const std::string &str);
        
        static bool isChar(const std::string &str); //static:pas besoin d instance pour les appeler car classe non instanciable
        static bool isInt(const std::string &str);
        static bool isFloat(const std::string &str);
        static bool isDouble(const std::string &str);
        static bool isPseudoLiteral(const std::string &str);

    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& other);
  
};