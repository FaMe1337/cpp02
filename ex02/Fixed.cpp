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

Fixed::Fixed() : _value(0){}

Fixed::Fixed(const int n) : _value(n << _literal){}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	_value = (int)roundf(f*(1 << _literal));
}

Fixed::Fixed(const Fixed& other) : _value(other._value){}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		_value = other._value;
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
	return (float)_value / (float)(1 << _literal);
}

int Fixed::toInt( void ) const
{
	return (int)_value >> _literal;
}


std::ostream& operator<<(std::ostream& o, const Fixed& a)
{
	o << a.toFloat();
	return o;
}