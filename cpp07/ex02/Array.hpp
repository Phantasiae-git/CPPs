/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:30:44 by phantasiae        #+#    #+#             */
/*   Updated: 2024/12/01 14:18:40 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
private:
    T* array;
    unsigned int size;

public:
    Array();
    Array(unsigned int size);
    Array(const Array &other);
    ~Array();
    
    Array &operator=(const Array &other);
    T &operator[](int other);
    int    size();

    class OutOfBoundsException:public std::exception
    {
    public:
        const char* what() const throw();
    };
};

template <typename T> Array<T>::Array()
{
    this->array= new T[0];
    this->size=0;
    // int * a = new int();
    // std::cout << a << std::endl;
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T> Array<T>::Array(unsigned int size) : size(size)
{
    this->array= new T[size];
    std::cout << "Array constructor called" << std::endl;
}

template <typename T> Array<T>::Array(const Array &other) : size(other.size)
{
    if(this->array)
        delete [] array;
    this->array= new T[size];
    for(int i=0; i<size; i++)
        this->array[i]=other.array[i];
    std::cout << "Array copy constructor called" << std::endl;
}

template <typename T> Array<T>::~Array()
{
    delete [] this->array;
    std::cout << "Array destructor called" << std::endl;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
    if(this->size!=other.size)
    {
        delete [] this->array;
        this->size=other.size;
        this->array= new T[this->size];
    }
    for(int i=0; i<size; i++)
        this->array[i]=other.array[i];
    return *this;
}

template <typename T> const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("index is out of bounds");
}

template <typename T>  T &Array<T>::operator[](int element)
{
    if(element>=size)
    {
        throw OutOfBoundsException();
    }
    return(this->array[element]);
}

template <typename T> int Array<T>::size()
{
    return this->size;
}

#endif