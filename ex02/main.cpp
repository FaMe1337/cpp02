/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:17:42 by marvin            #+#    #+#             */
/*   Updated: 2025/08/24 21:17:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << "same but commented" << std::endl;

		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << "a = " << a << std::endl;
		std::cout << "++a = " << ++a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a++ = " << a++ << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "--a = " << --a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a-- = " << a-- << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a = " << a-- << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "max a and b" << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << "\n--- Arithmetic Tests ---\n";

		Fixed a(3);
		Fixed b(2);

		Fixed c = a + b;
		std::cout << a << " + " << b << " = " << c << "\n";
		Fixed d = a - b;
		std::cout << a << " - " << b << " = " << d << "\n";
		Fixed e = a * b;
		std::cout << a << " * " << b << " = " << e << "\n";
		Fixed f = a / b;
		std::cout << a << " / " << b << " = " << f << "\n";
	}
	{
		Fixed a(3);
		Fixed b(2.5f);

		Fixed c = a + b;
		std::cout << a << " + " << b << " = " << c << "\n";
		Fixed d = a - b;
		std::cout << a << " - " << b << " = " << d << "\n";
		Fixed e = a * b;
		std::cout << a << " * " << b << " = " << e << "\n";
		Fixed f = a / b;
		std::cout << a << " / " << b << " = " << f << "\n";
	}
	{
		std::cout << "\n--- min/max Tests ---\n";

		Fixed a(10);
		Fixed b(2);

		std::cout << "a = " << a << ", b = " << b << "\n";
		std::cout << "min(a, b) = " << Fixed::min(a, b) << "\n";
		std::cout << "max(a, b) = " << Fixed::max(a, b) << "\n";

		const Fixed c(3), d(4);
		std::cout << "const c = " << c << ", const d = " << d << "\n";
		std::cout << "min(c, d) = " << Fixed::min(c, d) << "\n";
		std::cout << "max(c, d) = " << Fixed::max(c, d) << "\n";


		std::cout << "\n--- ++ and -- Tests ---\n";
		std::cout << "value original de a é: " << a << "\n";
		Fixed u;
		Fixed i;
		
		u = a++;
		std::cout << "value de a++ é: " << a << "\n";
		std::cout << "value de u é: " << u << "\n";
		i = a--;
		std::cout << "value de a-- é: " << a << "\n";
		std::cout << "value de i é: " << i << "\n";
		u = ++a;
		std::cout << "value de ++a é: " << a << "\n";
		std::cout << "value de u é: " << u << "\n";
		i = --a;
		std::cout << "value de --a é: " << a << "\n";
		std::cout << "value de i é: " << i << "\n";
	}
}