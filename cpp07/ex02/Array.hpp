/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:30:44 by phantasiae        #+#    #+#             */
/*   Updated: 2024/12/01 16:58:18 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
private:
    T* array;
    unsigned int length;

public:
    Array();
    Array(unsigned int length);
    Array(const Array &other);
    ~Array();
    
    Array &operator=(const Array &other);
    T &operator[](int other);
    int    size() const;

    class OutOfBoundsException:public std::exception
    {
    public:
        const char* what() const throw();
    };

    class NegativeIndexException:public std::exception
    {
    public:
        const char* what() const throw();
    };
};

template <typename T> Array<T>::Array()
{
    this->array= new T[0];
    this->length=0;
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T> Array<T>::Array(unsigned int length) : length(length)
{
    this->array= new T[length];
    std::cout << "Array constructor called" << std::endl;
}

template <typename T> Array<T>::Array(const Array &other) : length(other.length)
{
    this->array= new T[length];
    for(unsigned int i=0; i<this->length; i++)
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
    if(this->array)
        delete [] array;
    std::cout << "Array = operator overload called" << std::endl;
    this->length=other.length;
    this->array= new T[length];
    for(unsigned int i=0; i<this->length; i++)
        this->array[i]=other.array[i];
    return *this;
}

template <typename T> const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("index is out of bounds");
}

template <typename T> const char *Array<T>::NegativeIndexException::what() const throw()
{
	return ("index can't be negative");
}

template <typename T>  T &Array<T>::operator[](int element)
{
    if(element<0)
    {
        throw NegativeIndexException();
    }
    unsigned int idx=static_cast<unsigned int>(element);
    if(idx>=this->length)
    {
        throw OutOfBoundsException();
    }
    return(this->array[idx]);
}

template <typename T> int Array<T>::size() const
{
    return this->length;
}

#endif