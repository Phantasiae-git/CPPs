/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:44:43 by phantasiae        #+#    #+#             */
/*   Updated: 2024/11/27 14:57:54 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.cpp"

int main()
{
    Data a;
    a.n=1;
    uintptr_t num;
    num=Serializer::serialize(&a);
    Serializer::deserialize(num);
}