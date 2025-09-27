/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:09:00 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/27 13:30:20 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <stdint.h>

// On sérialise un pointeur (Data* → uintptr_t)
// on convertit un pointeur en un entier non signé puis on deserialise

typedef struct Data
{
    std::string name;
    int age;
}       Data;


class Serializer
{
    public :
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    
    private :
        Serializer();
        Serializer(const Serializer &copy);
        Serializer& operator=(const Serializer &other);
        ~Serializer();
};
