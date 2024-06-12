/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:26:23 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 14:02:59 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(const Ice &ice);
        Ice& operator=(const Ice &ice);

        virtual AMateria*   clone() const;
        virtual void        use(ICharacter& target);
};

#endif