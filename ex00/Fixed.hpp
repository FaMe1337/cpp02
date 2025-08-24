/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:24:16 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 16:24:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(); // normal constructor
		Fixed(const Fixed& cpy); // cpy constructor
		Fixed& operator=(const Fixed& other); // copy assigment operator
		~Fixed(); // normal destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );


	private:
		int _value;
		static const int _fixed_value = 8;
		
};

#endif