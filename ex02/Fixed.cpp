/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:17:47 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 21:17:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0){}

Fixed::Fixed(const int n) : _value(n << _literal){}

Fixed::Fixed(const float f) : _value((int)roundf(f*(1 << _literal))){}

Fixed::Fixed(const Fixed& other) : _value(other._value){}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed(){}

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

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed temp;

	temp.setRawBits(getRawBits() + other.getRawBits());
	return temp;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed temp;

	temp.setRawBits(getRawBits() - other.getRawBits());
	return temp;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed temp;

	temp.setRawBits(getRawBits() * other.getRawBits() >> _literal);
	return temp;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed temp;

	temp.setRawBits((getRawBits() *(1 <<_literal)) / other.getRawBits());
	return temp;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (getRawBits() > other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) const
{
	return (getRawBits() < other.getRawBits());
}
bool Fixed::operator>=(const Fixed& other) const
{
	return (getRawBits() >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other) const
{
	return (getRawBits() <= other.getRawBits());
}
bool Fixed::operator==(const Fixed& other) const
{
	return (getRawBits() == other.getRawBits());
}
bool Fixed::operator!=(const Fixed& other) const
{
	return (getRawBits() != other.getRawBits());
}

Fixed& Fixed::operator++()
{
	setRawBits(getRawBits() + 1);
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;

	setRawBits(getRawBits() + 1);
	return temp;
}
Fixed& Fixed::operator--()
{
	setRawBits(getRawBits() - 1);
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;

	setRawBits(getRawBits() - 1);
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;	
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;	
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;	
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;	
}