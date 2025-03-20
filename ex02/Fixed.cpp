/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:37:58 by gmalyana          #+#    #+#             */
/*   Updated: 2025/03/19 15:46:04 by gmalyana         ###   ########.fr       */
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
		setRawBits(other.getRawBits());
    return *this;
}
Fixed::~Fixed() {}

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
std::ostream& operator<<(std::ostream& stream, const Fixed& obj) {
    stream << obj.toFloat();
    return (stream);
}


Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}


bool Fixed::operator>(const Fixed& other) const {
    return (this->number > other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) const {
    return (this->number < other.getRawBits());
}
bool Fixed::operator>=(const Fixed& other) const {
    return (this->number >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other) const {
    return (this->number <= other.getRawBits());
}
bool Fixed::operator==(const Fixed& other) const {
    return (this->number == other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other) const {
    return (this->number != other.getRawBits());
}


Fixed& Fixed::operator++() {
    this->number += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->number += 1;
    return temp;
}

Fixed& Fixed::operator--() {
    this->number -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->number -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a.getRawBits() < b.getRawBits() ? a : b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a.getRawBits() > b.getRawBits() ? a : b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a.getRawBits() < b.getRawBits() ? a : b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a.getRawBits() > b.getRawBits() ? a : b);
}