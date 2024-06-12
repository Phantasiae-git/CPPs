/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:06:56 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 14:13:34 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    AMateria    *inventory[4];
public:
    Character();
    Character(std::string const &name);
    Character(Character const &character);
    Character&  operator=(const Character &character);
    ~Character();

    std::string const & getName() const;
    void    equip(AMateria* m);
    void     unequip(int idx);
    void    use(int idx, ICharacter& target);
};

#endif