/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:18:29 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 19:18:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int n) : _value(n << _literal)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f) : _value((int)roundf(f*(1 << _literal)))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	return _value;
}

void Fixed::setRawBits( int const raw )
{
	_value = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)getRawBits() / (1 << _literal);
}

int Fixed::toInt( void ) const
{
	return (int)getRawBits() >> _literal;
}

std::ostream& operator<<(std::ostream& o, const Fixed& a)
{
	o << a.toFloat();
	return o;
}