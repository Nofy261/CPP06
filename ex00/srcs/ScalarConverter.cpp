/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:37 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/25 14:13:37 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib> //atof
#include <iomanip>
#include <limits>
#include <sstream>
#include <cerrno> // ernno strtol


static bool isPseudoLiteral(const std::string &str) 
{
    if (str == "nan" || str == "+inf" || str == "inf" || str == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl; // a voir si c'est accepter d'ecrire manuellement
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


//long int strtol (const char* str, char** endptr, int base);
// gerer les espaces et/ou tab avant Ex:"   77880"

bool isInt(const std::string &str)
{
    // if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
    //     return false;
    
    // for(int i = 1; i < str.size(); i++)
    // {
    //     if (!isdigit(str[i]))
    //         return false;
    // }
    
   // convertir en long
    char *end;
    errno = 0;
    long int c = strtol(str.c_str(), &end, 10);
    
    if (*end != '\0') // strtol n'a pas lu la chaine jusqu a la fin car caractere invalide trouvé  Ex: 123adc 
        return false;
    
    if (errno == ERANGE) // si overflow d'un long int
    {
        std::cout << "Error 1: Value is invalid ." << std::endl;
        return false;
    }
   
    if (c > INT_MAX || c < INT_MIN)
    {
        std::cout << "Error 2: Value is out of range for int." << std::endl;
        return false;
    }
    return true;
}


 


// float x = .5f == 0.5f CAS VALIDE A GERER 
// ./convert .5f cas a gerer ?? 
// a tester ++ -- +. -.
// il faut gerer les espace et tab au debut Ex : ./convert "  +234f" ce n'est pas gerer ici
static bool isFloat(const std::string &str)
{
    
    //int i = 0;
    if (str.size() <= 1)
        return false;
    if (str[str.length() - 1] != 'f')
        return false;
    // while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	// 	i++;
    if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
    {
        std::cout << "Error 1: Invalid float" << std::endl;
        return false;
    }
 
    std::string s = str.substr(0, str.length() - 1); // on enleve le f en dernier
       
    int count_dot = 0;   
    for (unsigned long int i = 1; i < s.length(); i++) // on commence a 1 car on a defa validé ou pas le 1er caractere
    {
        if (s[i] == '.')
            count_dot++;       
        if (count_dot > 1)
            return false;
        if (!isdigit(s[i]) && s[i] != '.') // && str[0] != '+' && str[0] != '-')
        {
            std::cout << "Error 2: Invalid float" << std::endl;
            return false;
        }
    }
    return true; 
}


// s'il y a un point mais pas de f
// a gerer +. ou -. ou ++ -- invalide
// il faut gerer les espace et tab au debut Ex : ./convert "  +234f"
static bool isDouble(const std::string &str)
{
    if (str.size() <= 1)
        return false;
    // int i = 0;
    // while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	// 	i++;
    if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
    {
        std::cout << "Error 1: Invalid double" << std::endl;
        return false;
    }
    
    if ((str[0] == '+' || str[0] == '-') && (!isdigit(str[1])))
    {
        std::cout << "Error 2: Invalid double" << std::endl; // ./convert ++kl a tester
        return false;
    }
    
    int count_dot = 0;   
    for (unsigned long int i = 1; i < str.size(); i++) // on commence a 1 car on a defa validé ou pas le 1er caractere
    {
        if (str[i] == '.')
            count_dot++;       
        if (!isdigit(str[i]) && str[i] != '.')
        {
            std::cout << "Error 3: Invalid double" << std::endl; // ./convert +85j  a tester
            return false;
        }
    }
    if (count_dot != 1)
        return false;
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
    if (isInt(str))
    {
        int c = atoi(str.c_str());
        
        if (c < 0 || c > 127)
            std::cout << "char: impossible" << std::endl; 
        else if (c < 32 || c == 127)
            std::cout << "char: Non displayable" << std::endl;
        else      
            std::cout << "char: " << static_cast<char>(c) << std::endl;
        std::cout << "int: "<< c << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" <<std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    }
    
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

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(f) << "f" <<std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
    }
    else if (isDouble(str)) // A TESTER TOUS LES CAS
    {
        std::stringstream ssd(str);
        double d;
        ssd >> d;

        if (d < 0 || d > 127)
            std::cout << "char: impossible" << std::endl; 
        else if (d < 32 || d == 127)
            std::cout << "char: Non displayable" << std::endl;
        else      
            std::cout << "char: " << static_cast<char>(d) << std::endl;

        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl; 
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) <<"f"<<std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
    }
    // else // verifier dans le main ?
    // {
    //     std::cout << "Invalid literal." << std::endl;
    //     // pas d argument ou trop d argument donné 
    // }
} 