/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:06:11 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/27 14:25:08 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void)
{
    Data obj;
    obj.name = "Bob";
    obj.age = 46;
    
    Data *ptr = &obj;
    
    uintptr_t nb;
    nb = Serializer::serialize(ptr);
    
    std::cout << "serialized address: " << ptr << std::endl;
    std::cout << "serialized value: " << nb << std::endl;
    std::cout << "ptr->name: " << ptr->name << std::endl;
    std::cout << "ptr->age: " << ptr->age << std::endl;
    std::cout << std::endl;
    std::cout << "obj address: " << &obj << std::endl;
    std::cout << "obj.name: " << obj.name << std::endl;
    std::cout << "obj.age: " << obj.age << std::endl;
    std::cout << std::endl;
    
    ptr = Serializer::deserialize(nb);
    
    std::cout << "deserialized address: " << ptr << std::endl;
    std::cout << "deserialized value: " << nb << std::endl;
    std::cout << "ptr->name: " << ptr->name << std::endl;
    std::cout << "ptr->age: " << ptr->age << std::endl;
    std::cout << std::endl;
    
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "obj adress: " << &obj << std::endl;
    
    return 0;
}
