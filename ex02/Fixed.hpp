/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:38:07 by gmalyana          #+#    #+#             */
/*   Updated: 2025/03/07 16:30:04 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <cmath>

class Fixed{
	private:
		int number;
		static const int FractionalPartBits;
	public:
		Fixed();
		Fixed(const int Value);
		Fixed(const float Value); 
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw);

		Fixed operator+(const Fixed &obj);
		
};

const int Fixed::FractionalPartBits = 8;

#endif