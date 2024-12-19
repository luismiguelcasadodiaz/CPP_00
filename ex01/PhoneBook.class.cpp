#include <iostream>
#include "PhoneBook.class.hpp"
#include <limits>

PhoneBook::PhoneBook(void)
{
    std::cout << "PhoneBook's Constructor called" << std::endl;
	this->_used = 0;
    this->_index = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook's Destructor called" << std::endl;
    return ;
}

void PhoneBook::add(Contact& one_contact)
{
    if (this->_index == MAX_CONTACTS)
		this->_index = 0;
	this->list[this->_index] = one_contact;
    this->_used +=1;
    this->_index +=1;
	return ;
}

void PhoneBook::search(void) const
{
	int     index;
    int     the_index;
    bool    enrango;

    if (!this->_used)
        std::cout << "Nothing yet recorded inside PhoneBook" << std::endl;
    else
    {
        this->list[0].view_head();
        index = 0;
        while (index < this->_used && index < MAX_CONTACTS)
        {
            this->list[index].view_short(index);
            index ++;
        }    
        this->list[0].view_foot();
        enrango = false;
        while (!enrango)
        {
            while (true)
            {
                std::cout << "Enter index of the entry to display >";
                std::cin >> the_index;
                if (std::cin.fail()) 
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Input does not represents an integer.\n";
                } 
                else
                    break;
            }
            if ((0 <= the_index) && (the_index <= this->_used))
                enrango = true;
            else
                std::cout << "The index >" << the_index << "< does not exists" << std::endl;
        }
        this->list[the_index].view_long();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
