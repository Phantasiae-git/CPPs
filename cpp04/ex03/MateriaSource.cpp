/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:18:08 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 15:36:00 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout<<"MateriaSource default constructor called"<<std::endl;
    for (int i=0; i<4; i++)
        materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource&materiasource)
{
    std::cout<<"MateriaSource copy constructor called"<<std::endl;
	for (int i=0; i<4; i++)
            materias[i] = materiasource.materias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource &materiasource)
{
    for (int i=0; i<4; i++)
            materias[i] = materiasource.materias[i];
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout<<"MateriaSource destructor called"<<std::endl;
    for(int i=0; i<4; i++)
    {
        if(this->materias[i])
            delete this->materias[i];
    }
}

void	MateriaSource::learnMateria(AMateria *materia)
{
    if (materia==NULL)
	{
		std::cout<<"Invalid materia"<<std::endl;
		return;
	}
	for (int i=0; i<4; i++)
	{
		if (this->materias[i]==NULL)
		{
			this->materias[i]=materia;
			std::cout<<"Materia "<<this->materias[i]->getType()<<" learned"<<std::endl;
			return;
		}
	}
    std::cout<<"Inventory full"<<std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for(int i=0; i<4; i++)
    {
        if (materias[i] && materias[i]->getType()==type)
            return materias[i]->clone();
    }
    return(0);
}

