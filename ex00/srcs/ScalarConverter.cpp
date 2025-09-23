/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:37 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/23 12:02:05 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::~ScalarConverter(){}

bool ScalarConverter::isChar(const std::string &str)
{
    if (str.length() == 1 && !isdigit(str[0]))
        return true;
    else
    {
        std::cout << "char: impossible" << std::endl;  
        std::cout << "int: impossible" << std::endl; 
        std::cout << "float: impossible" << std::endl; 
        std::cout << "double: impossible" << std::endl;  
        return false;
    }
}

bool ScalarConverter::isPseudoLiteral(const std::string &str)
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


// bool isInt(const std::string &str)
// {
    
// }

//float = 67.0f  65f 

// bool isFloat(const std::string &str)
// {
//     int count_dot = 0;
    
//     for (int j = 0; j < str.size(); j++)
//     {
//         if (str[j] == '.')
//             count_dot++;
//     }
//     if (count_dot > 1)
//         return false;
//     for (int i = 0; i < str.size(); i++)
//     {
//         if (!isdigit(str[0]))
//             return false;
        
//         // si str[i] n est pas un point n est pas un chiffre et n'est pas le dernier caractere
//         if (!isdigit(str[i]) && str[i] != '.' && str[i] != str.length() - 1)
//             return false;
        
//         // si le dernier caract n'est pas un f
//         if (str.length() - 1 != 'f')
//             return false;
//     }
//     return true;
// }


// 56.f
// float x = .5f == 0.5f CAS VALIDE A GERER 

bool isFloat(const std::string &str)
{
    if (str.size() <= 1)
        return false;
    if (str[str.length() - 1] != 'f')
        return false;
    if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
        return false;
        
    std::string s = str.substr(0, str.length() - 1); // on enleve le f en dernier
       
    int count_dot = 0;   
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
            count_dot++;       
        if (count_dot > 1)
            return false;
        if (!isdigit(s[i]) && s[i] != '.')
            return false;
    }
    return true; 
}


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
    // else if (isFloat(str)) //ex : 42.0f
    // {
    //     std::cout << "char: " << 



        
    //     // - Convertir str en float
    //     // - char:
    //     //     - Si dans la plage [0, 127]
    //     //         - Si affichable : afficher
    //     //         - Sinon : "Non displayable"
    //     //     - Sinon : "impossible"
    //     // - int:
    //     //     - Si valeur = nanf ou inff → "impossible"
    //     //     - Si dans INT_MIN/INT_MAX → afficher (tronqué)
    //     //     - Sinon → "impossible"
    //     // - double:
    //     //     - Toujours possible → afficher  
    // }
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