/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespaces.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:17:55 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/10 08:25:22 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	gl_var = 1;
int	f( void ) { return (2); }

namespace	Foo
{
	int	gl_var = 3;
	int	f( void ) { return (4); }
}

namespace	Bar
{
	int	gl_var = 5;
	int	f( void ) { return (6); }
}

namespace Muf = Bar;

int	main ( void )
{
	printf( "gl_var:     [%d]\n", gl_var );
	printf( "f():        [%d]\n\n", f() );

	printf( "gl_var:     [%d]\n", Foo::gl_var );
	printf( "f():        [%d]\n\n", Foo::f() );

	printf( "gl_var:     [%d]\n", Bar::gl_var );
	printf( "f():        [%d]\n\n", Bar::f() );

	printf( "gl_var:     [%d]\n", Muf::gl_var );
	printf( "f():        [%d]\n\n", Muf::f() );

	printf( "gl_var:     [%d]\n", ::gl_var );
	printf( "f():        [%d]\n\n", ::f() );

	return (0);
}

