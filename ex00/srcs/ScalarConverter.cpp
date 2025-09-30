/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:37 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/30 16:57:13 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <climits> 
#include <sstream>
#include <cerrno>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    *this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter(){}

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

bool isInt(const std::string &str)
{
    char *end;
    errno = 0;
    long int c = strtol(str.c_str(), &end, 10);
    
    while (*end != '\0')
    {
        if (!std::isspace(static_cast<unsigned char>(*end)))
            return false;
        end++;
    }  
    if (errno == ERANGE)
        return false;
    if (c > INT_MAX || c < INT_MIN)
        return false;
    return true;
}


static bool isFloat(const std::string &str)
{
    if (str.size() <= 1)
        return false;
    if (str[str.length() - 1] != 'f')
        return false;
    unsigned long int i = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;    
    if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-')
        return false;
    i++;
    if ((str[i - 1] == '+' || str[i - 1] == '-') && (!isdigit(str[i])))
        return false;
    if (isdigit(str[i - 1]) && (str[i] != '.' && !isdigit(str[i])))
        return false;

    std::string s = str.substr(0, str.length() - 1);
       
    unsigned long int count_dot = 0;
    while (i < s.size())
    {
        if (s[i] == '.')
            count_dot++;
        if (s[i] != '.' && !isdigit(s[i]))
            return false;
        i++;
    }
    if (count_dot > 1)
        return false;
    return true; 
}


static bool isDouble(const std::string &str)
{
    if (str.size() <= 1)
        return false;
    unsigned long int i = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;    
    if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-')
        return false;
    i++;
    if ((str[i - 1] == '+' || str[i - 1] == '-') && (!isdigit(str[i])))
        return false;
    if (isdigit(str[i - 1]) && (str[i] != '.' && !isdigit(str[i])))
        return false;
    unsigned long int count_dot = 0;
    while (i < str.size())
    {
        if (str[i] == '.')
            count_dot++;
        if (str[i] != '.' && !isdigit(str[i]))
            return false;
        i++;
    }
    
    std::stringstream ssd(str);
    double d;
    ssd >> d;
    
    if (count_dot > 1)
        return false;
    if (count_dot == 0 && ((d > std::numeric_limits<int>::max()) || (d < std::numeric_limits<int>::min())))
        return true;
    if (count_dot == 0)
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
            std::cout << "char: " << "'" << str << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" <<std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
        }
        else if (!isprint(str[0]))
        {
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) << "f" <<std::endl;
            std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
        }
    }
    else if (isInt(str))
    {
        int c = atoi(str.c_str());
        
        if (c < 0 || c > 127)
            std::cout << "char: impossible" << std::endl; 
        else if (c < 32 || c == 127)
            std::cout << "char: Non displayable" << std::endl;
        else      
            std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
        std::cout << "int: "<< c << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" <<std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    }
    else if (isFloat(str))
    {
        std::string s = str.substr(0, str.length() - 1);
        
        float f = atof(s.c_str());
        if (f < 0 || f > 127)
            std::cout << "char: impossible" << std::endl; 
        else if (f < 32 || f == 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
        
        std::stringstream ssd(s);
        double d;
        ssd >> d;
        
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl; 
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(f) << "f" <<std::endl;
        //std::cout << "float: " <<  f <<std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
    }
    // else if (isDouble(str))
    // {
    //     std::stringstream ssd(str);
    //     double d;
    //     ssd >> d;

    //     if (d < 0 || d > 127)
    //         std::cout << "char: impossible" << std::endl; 
    //     else if (d < 32 || d == 127)
    //         std::cout << "char: Non displayable" << std::endl;
    //     else      
    //         std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;

    //     if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
    //         std::cout << "int: impossible" << std::endl; 
    //     else
    //         std::cout << "int: " << static_cast<int>(d) << std::endl;

    //     std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) <<"f"<<std::endl;
    //     std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
    // }

    else if (isDouble(str))
    {
        std::stringstream ssd(str);
        double d;
        ssd >> d;

        if (d < 0 || d > 127)
            std::cout << "char: impossible" << std::endl; 
        else if (d < 32 || d == 127)
            std::cout << "char: Non displayable" << std::endl;
        else      
            std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;

        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl; 
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) <<"f"<<std::endl;

        if (ssd.fail())
            std::cout << "double: impossible" << std::endl;
        else if (d != d || d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity())
            std::cout << "double: impossible" << std::endl;
        else
            //std::cout << "double: " << std::scientific << d << std::endl;
            std::cout << "double: " << d << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

//179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368
