/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:37:58 by gmalyana          #+#    #+#             */
/*   Updated: 2025/03/07 16:47:08 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractionalPartBits = 8;

Fixed::Fixed() {
    this->number = 0;
}
Fixed::Fixed(const int Value){
    this->number = Value << Fixed::FractionalPartBits;
}

Fixed::Fixed(const float Value){
    this->number = roundf(Value * (1 << Fixed::FractionalPartBits));
}

Fixed::Fixed(const Fixed &other){
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
    if(this != &other)
        this->number = other.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    return this->number;
}

void Fixed::setRawBits(int const raw){
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

Fixed operator+(const Fixed& obj1, const Fixed& obj2) {
    Fixed add;
    add.setNumber(obj1.getNumber() + obj2.getNumber()); // Use setter if available
    return add;
}