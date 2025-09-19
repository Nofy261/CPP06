/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:17:37 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/19 12:29:25 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string &str)
{
    // quel est le type de l argument passée 
  
    if (isPseudoLiteral(str))
    {
        si str est "nan" ou "+inf" ou "-inf" alors
            afficher "char: impossible"
            afficher "int: impossible"
            afficher "float: <valeur correspondante suivie de f>"
            afficher "double: <valeur>"
        sinon si str est "nanf" ou "+inff" ou "-inff" alors
            afficher "char: impossible"
            afficher "int: impossible"
            afficher "float: <valeur>"
            afficher "double: <valeur sans le f>"
    }
    else if (isChar(str))
    {
        -on verifie le nombre de caractere :
            -->si str.length() != 1
                -> message de conversion impossible pout tout
            -->si str.length() == 1  (ex : 'A')
                -> on l affiche en char  (char = 'A')
                -> on convertit en int et on affiche la valeur en int (int = 65 voir ascii)
                -> on convertit le int en float et affiche le float (float = 65.0f)
                -> on convertit le int en double et affiche le double (double = 65.0)
    }
    
    if (isInt(str))
    {
        si c'est un int : 
        ->on verifie si ne depasse pas le int max et min : si overflow message d overflow
        ->sinon on le convertit en int 
        *on le convertit en char : 
        -> on verifie si la valeur est entre -128 a 127 (char valide en c++) : 
            -->si oui : on verifie si c est affichable : si affichable on affiche si non message non affichable
            -->si non : messsage conversion impossible
        *on le convertit en float et on affiche le resultat en rajoutant le "f" a la fin.
        *on le convertit en double et -------*------*---------
    }
    else if (isFloat(str)) ex : 42.0f
    {
        - Convertir str en float
        - char:
            - Si dans la plage [0, 127]
                - Si affichable : afficher
                - Sinon : "Non displayable"
            - Sinon : "impossible"
        - int:
            - Si valeur = nanf ou inff → "impossible"
            - Si dans INT_MIN/INT_MAX → afficher (tronqué)
            - Sinon → "impossible"
        - double:
            - Toujours possible → afficher  
    }
    else if (isDouble(str))
    {
        - Convert str en double
        - char:
            - Si dans [0,127]
                -Si affichable → afficher
                - Sinon → "Non displayable"
            - Sinon → "impossible"
        - int:
            - Si nan / inf → "impossible"
            - Si dans INT range → afficher (tronqué)
            - Sinon → "impossible"
        - float:
            - Toujours possible → afficher avec .0f si besoin
        - double:
            - Affichage direct (avec .0 si pas de décimale) 
    }
    else
    {
        std::cout << "Invalid literal." << std::endl
    }
} 