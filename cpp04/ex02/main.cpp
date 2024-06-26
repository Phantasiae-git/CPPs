/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:51:46 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 11:59:08 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;//should not create a leak
delete i;

Dog a;
Dog b;
Dog c;

a.getBrain()->setIdea("food", 0);
a.getBrain()->setIdea("invalid", 100);
a.getBrain()->setIdea("yippee", 99);
std::cout<<"-------------------------------------"<<std::endl;
a.getBrain()->printIdeas();
std::cout<<"-------------------------------------"<<std::endl;
b.getBrain()->setIdea("hihi", 0);
b.getBrain()->setIdea("haha", 0);
b.getBrain()->setIdea("b idea", 99);
a=b;
a.getBrain()->printIdeas();
a=c;

// std::cout<<"-------------------------------------"<<std::endl;

Animal* animals[4];

for(int i=0;i<2;i++)
    animals[i]=new Dog();
for(int i=2;i<4;i++)
    animals[i]=new Cat();

std::cout<<"-------------------------------------"<<std::endl;
Dog *dogA=new Dog;
Dog *dogC=new Dog();
Dog *dogB=new Dog(*dogA);
*dogC=*dogB;
delete dogA;
delete dogB;
delete dogC;
// std::cout<<"-------------------------------------"<<std::endl;
Cat *catA=new Cat;
Cat *catC=new Cat;
Cat *catB=new Cat(*catA);
*catC=*catB;
delete catA;
delete catB;
delete catC;
std::cout<<"-------------------------------------"<<std::endl;
for (int i=0;i<4;i++)
    delete animals[i];

// Animal a;

return 0;
}