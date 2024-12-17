#include <iostream>
#include "Sample.class.hpp"
#include "Sample1.class.hpp"

int main ( void )
{
    Sample instance;
    Sample1 instance1('a', 42, 4.0f);

    instance.foo = 41;
    std::cout << "instance.foo " << instance.foo << std::endl;
    instance.bar();
    return (0);
}