/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:47:04 by phantasiae        #+#    #+#             */
/*   Updated: 2024/11/30 19:40:32 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base yay;

    Base *a= yay.generate();
    yay.identify(a);

    C c;
    Base &test=c;

    yay.identify(test);
    yay.identify(*a);

    delete a;
}