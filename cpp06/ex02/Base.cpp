/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:50:41 by phantasiae        #+#    #+#             */
/*   Updated: 2024/11/28 11:36:15 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}

Base * Base::generate(void)
{
    std::srand(std::time(0));
    Base *bs;
    int r=std::rand()%3;
    switch (r)
    {
    case 0:
    {
        bs = new A();
        //std::cout << "created A" << std::endl;
        break;
    }
    case 1:
    {
        bs = new B();
        //std::cout << "created B" << std::endl;
        break;
    }
    case 2:
    {
        bs = new C();
        //std::cout << "created C" << std::endl;
        break;
    }
    default:
        break;
    }
    return bs;
}

void Base::identify(Base* p)
{
    A *a=dynamic_cast<A *>(p);
    if(a==NULL)
    {
        B *b=dynamic_cast<B *>(p);
        if(b==NULL)
        {
            C *c=dynamic_cast<C *>(p);
            if(c==NULL)
                std::cout << "idk provavelmente isso é só lixo" << std::endl;
            else
                std::cout << "It's type C!" << std::endl;
        }
        else
            std::cout << "It's type B!" << std::endl;
    }
    else
        std::cout << "It's type A!" << std::endl;
}

void Base::identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "It's type A!" << std::endl;
        (void)a;
    }
    catch (std::exception& e)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            std::cout << "It's type B!" << std::endl;
            (void)b;
        }
        catch (std::exception& e)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                std::cout << "It's type C!" << std::endl;
                (void)c;
            }
            catch (std::exception& e)
            {
                std::cout << "idk provavelmente isso é só lixo" << std::endl;
            }
        }
    }
}