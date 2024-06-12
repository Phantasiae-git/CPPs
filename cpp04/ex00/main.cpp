/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:51:46 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 11:04:52 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "------------------" << std::endl;
    WrongCat a;
    a.makeSound();
    std::cout << "------------------ AS WRONG ANIMAL POINTER: -----------------------" << std::endl;
    WrongAnimal *wrong= new WrongCat();
    wrong->makeSound();
    wrong->getType();
    std::cout << "------------------" << std::endl;
    delete wrong;
    delete meta;
    delete j;
    delete i;
return 0;
}