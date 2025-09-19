/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:30 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/19 10:59:54 by nolecler         ###   ########.fr       */
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

    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& other);
  
};