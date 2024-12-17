#include <iostream>
#include "Sample1.class.hpp"

Sample1::Sample1( char p1, int p2, float p3 ): a1(p1), a2(p2), a3(p3)
{
    std::cout << "Constructor Sample1 called" << std::endl;
    std::cout << "this->a1 = " << this->a1 << std::endl;
    std::cout << "this->a2 = " << this->a2 << std::endl;
    std::cout << "this->a3 = " << this->a3 << std::endl;
    this->bar();
    return ;

}

Sample1::~Sample1( void )
{
    std::cout << "Destructor Sample1 called" << std::endl;
    return ;
}

void    Sample1::bar( void )
{
    std::cout << "Sample1's Member function bar called" << std::endl;
    return ;
}