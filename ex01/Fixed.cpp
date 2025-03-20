/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:16:29 by gmalyana          #+#    #+#             */
/*   Updated: 2025/03/19 12:52:00 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractionalPartBits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}

Fixed::Fixed(const int Value){
    std::cout << "Int constructor called" << std::endl;
    this->number = Value << Fixed::FractionalPartBits;
}

Fixed::Fixed(const float Value){
    std::cout << "Float constructor called" << std::endl;
    this->number = roundf(Value * (1 << Fixed::FractionalPartBits));
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
		setRawBits(other.getRawBits());
    return *this;
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int    Fixed::getRawBits() const {
    return this->number;
}

void     Fixed::setRawBits(int const raw){
    this->number = raw;
}

int Fixed::toInt( void ) const{
    return (this->number >> Fixed::FractionalPartBits);
}

float Fixed::toFloat() const{
    return ((float)this->number / (1 << Fixed::FractionalPartBits));
}

std::ostream &operator<<(std::ostream &stream, const Fixed &obj) {
    stream << obj.toFloat();
    return (stream);
}