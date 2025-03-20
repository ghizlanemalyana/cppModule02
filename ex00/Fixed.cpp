/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:56:53 by gmalyana          #+#    #+#             */
/*   Updated: 2025/03/17 17:41:42 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractionalPartBits = 8;

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    num = 0;
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
	this->num = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other){
    if(this != &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		setRawBits(other.getRawBits());
	}
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl; 
    return num;
}

void     Fixed::setRawBits(int const raw){
    num = raw;
}