/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:34:31 by nolecler          #+#    #+#             */
/*   Updated: 2025/10/02 11:46:46 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include "ctime"
#include <cstdlib>


Base * generate(void)
{
    int choice = rand() % 3;
    switch (choice)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        default :
            return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type A" << std::endl;
        return;
    }
    catch (std::exception &e)
    {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type B" << std::endl;
        return;
    }
    catch (std::exception &e)
    {}
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type C" << std::endl;
        return;
    }
    catch (std::exception &e)
    {}
    std::cout << "Unknown Type" << std::endl;
}


int main()
{
    srand(time(0));
    Base* base = generate();
    identify(base);
    identify(*base);

    delete base;

	return 0;
}