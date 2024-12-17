#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void )
{
    std::cout << "Constructor Sample called" << std::endl;
    this->foo = 42;
    std::cout << "this->foo = " << this->foo << std::endl;
    this->bar();
    return ;

}

Sample::~Sample( void )
{
    std::cout << "Destructor Sample called" << std::endl;
    return ;
}

void    Sample::bar( void )
{
    std::cout << "Sample 's Member function bar called" << std::endl;
    return ;
}
