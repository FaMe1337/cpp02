/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:17:44 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 21:17:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed(); // normal constructor
		Fixed(const int); // constructor for int
		Fixed(const float); // constructor for float
		Fixed(const Fixed& cpy); // cpy constructor
		Fixed& operator=(const Fixed& other); // copy assigment operator
		~Fixed(); // normal destructor
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		
		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed&a, Fixed&b);
		static const Fixed& min(const Fixed&a, const Fixed&b);
		static Fixed& max(Fixed&a, Fixed&b);
		static const Fixed& max(const Fixed&a, const Fixed&b);
		
	private:
		int _value;
		static const int _literal = 8;
		
};

std::ostream& operator<<(std::ostream& o, const Fixed& a);

#endif