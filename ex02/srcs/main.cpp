/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:34:31 by nolecler          #+#    #+#             */
/*   Updated: 2025/09/27 14:53:30 by nolecler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include "time.h"


//dynamicast test si l'objet pointer par Base* est tel type si oui il retourne 
// un nouveau pointeur du type demandé sinon retourne nullptr

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

// on veut identifier le type reel de l objet
void identify(Base* p)
{
   // dynamicast va convertir le pointeur p en un pointeur de type de lobjet A* ou B* ou C* 
   // si cela reussit cela veut dire qu il s agit bien de l'objet en question et
   // dynamicast retourne le nouveau pointeur B* A* ou C*
   // sinon retourne nullptr
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
    // dynamicast essaye de convertir la refernece p en A& ou B& ou C&
    // si le cast reussit on sait que c est A sinon une exception est levee avec catch 
    // une nouvelle reference est creer qui reference le mm objet que p
    try 
    {
        //dynamic_cast<A&>(p) retourne une réf vers l’objet A si p référence vraiment un A
        //Si p n’est pas un A, le cast lève une exception
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