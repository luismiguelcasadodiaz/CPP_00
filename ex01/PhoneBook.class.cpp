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

void PhoneBook::add(Contact& one_contact)
{
    std::cout << "añadir\n";
    //if (this->_used == MAX_CONTACTS)
	//	this->_used = 0;
	this->list[this->_used] = one_contact;
    //this->used +=1; 
	return ;
}

void PhoneBook::search(void) const
{
	std::cout << "buscar\n";
}

