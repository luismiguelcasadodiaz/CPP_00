#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void )
{
    std::cout << "Cosntructor called" << std::endl;
    return ;

}

Sample::~Sample( void )
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void    Sample::bar( void )
{
    std::cout << "Member function bar called" << std::endl;
    return ;
}
