/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:37 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/24 14:48:00 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib> //atof
#include <iomanip>
#include <limits>
#include <sstream>

static bool isPseudoLiteral(const std::string &str)
{
    if (str == "nan" || str == "+inf" || str == "inf" || str == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return true;
    }
    else if (str == "nanf" || str == "+inff" || str == "inff" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
        return true;
    }
    return false;
}

static bool isChar(const std::string &str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return true; 
    return false;
}



// bool isInt(const std::string &str)
// {
    
// }

//float = 67.0f  65f 

// 56.f
// float x = .5f == 0.5f CAS VALIDE A GERER 

static bool isFloat(const std::string &str)
{
    if (str.size() <= 1)
        return false;
    if (str[str.length() - 1] != 'f')
        return false;
    if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
        return false;
        
    std::string s = str.substr(0, str.length() - 1); // on enleve le f en dernier
       
    int count_dot = 0;   
    for (unsigned long int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
            count_dot++;       
        if (count_dot > 1)
            return false;
        if (!isdigit(s[i]) && s[i] != '.' && str[0] != '+' && str[0] != '-')
            return false;
    } 
    return true; 
}

// static bool isDouble(const std::string &str)
//{}


void ScalarConverter::convert(const std::string &str)
{ 
  
    if (isPseudoLiteral(str))
        return;
    else if (isChar(str))
    {
        if (isprint(str[0]))
        {
            std::cout << "char: " << str << std::endl;
            std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
            std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
        }
        else if (!isprint(str[0])) // a tester tout les cas
        {
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
            std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
        }
    }
    
    // if (isInt(str))
    // {
    //     si c'est un int : 
    //     ->on verifie si ne depasse pas le int max et min : si overflow message d overflow
    //     ->sinon on le convertit en int 
    //     *on le convertit en char : 
    //     -> on verifie si la valeur est entre -128 a 127 (char valide en c++) : 
    //         -->si oui : on verifie si c est affichable : si affichable on affiche si non message non affichable
    //         -->si non : messsage conversion impossible
    //     *on le convertit en float et on affiche le resultat en rajoutant le "f" a la fin.
    //     *on le convertit en double et -------*------*---------
        // int x = 5;
        // double y = static_cast<double>(x);
    //}
    
    else if (isFloat(str))
    {
        float f = atof(str.c_str());
        
        if (f < 0 || f > 127)
            std::cout << "char: impossible" << std::endl; 
        else if (f < 32 || f == 127)
            std::cout << "char: Non displayable" << std::endl;
        else      
            std::cout << "char: " << static_cast<char>(f) << std::endl;
            
        std::stringstream ssd(str);
        double d;
        ssd >> d;
        
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl; 
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;

        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
    }
    // else if (isDouble(str))
    // {
    //     - Convert str en double
    //     - char:
    //         - Si dans [0,127]
    //             -Si affichable → afficher
    //             - Sinon → "Non displayable"
    //         - Sinon → "impossible"
    //     - int:
    //         - Si nan / inf → "impossible"
    //         - Si dans INT range → afficher (tronqué)
    //         - Sinon → "impossible"
    //     - float:
    //         - Toujours possible → afficher avec .0f si besoin
    //     - double:
    //         - Affichage direct (avec .0 si pas de décimale) 
    // }
    // else
    // {
    //     std::cout << "Invalid literal." << std::endl;
    //     // pas d argument ou trop d argument donné 
    // }
} 