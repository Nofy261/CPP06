/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:09:00 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/02 11:52:51 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <iostream>
#include <stdint.h>

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
