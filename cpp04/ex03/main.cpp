/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:36:32 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 15:43:56 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() 
{
IMateriaSource* src = new MateriaSource();
std::cout<<"--------------------------------"<<std::endl;
src->learnMateria(new Ice());
src->learnMateria(new Cure());
src->learnMateria(NULL);//nothing happens
std::cout<<"--------------------------------"<<std::endl;
ICharacter* me = new Character("me");
AMateria* tmp;
std::cout<<"--------------------------------"<<std::endl;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
me->equip(NULL);//nothing happens
std::cout<<"--------------------------------"<<std::endl;
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
me->use(2, *bob);//invalid index
std::cout<<"--------------------------------"<<std::endl;
me->unequip(1);
me->unequip(1);//invalid index
std::cout<<"--------------------------------"<<std::endl;
delete tmp;
tmp = src->createMateria("yaa"); //invalid materia
std::cout<<"--------------------------------"<<std::endl;
delete bob;
delete me;
delete src;

//new AMateria(); -> not supposed to work

return 0;
}