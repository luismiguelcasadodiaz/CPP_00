#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "PhoneBook's Constructor called" << std::endl;
    this->_used = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook's Destructor called" << std::endl;
    return ;
}

PhoneBook::add(Contact one_contact)
{
    this->list[this->_used] = one_contact;
    this->used +=1; 
}

