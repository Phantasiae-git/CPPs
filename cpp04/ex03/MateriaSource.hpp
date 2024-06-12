/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:15:37 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 15:22:33 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* materias[4];
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource &materiasource);
    MateriaSource&  operator=(const MateriaSource &materiasource);

    AMateria* getMateria( std::string const & type );
    AMateria* createMateria( std::string const & type );
    void learnMateria( AMateria* );
};

#endif