#include <iostream>
#include <iomanip>
#include "Contact.class.hpp"

int Contact::_ordinal = 0;

Contact::Contact(std::string one_first_name, 
                std::string one_last_name,
                std::string one_nickname,
                std::string one_phone_number,
                std::string one_darkest_secret): 
                first_name(one_first_name),                 
                last_name(one_last_name),
                nickname(one_nickname),                
                phone_number(one_phone_number),                
                darkest_secret(one_darkest_secret)
{                
    Contact::_ordinal +=1;
    std::cout << "Contact " << Contact::_ordinal << "'s Constructor called" << std::endl;
    return ;
};

Contact::Contact(void)
{
    Contact::_ordinal +=1;
    std::cout << "Contact " << Contact::_ordinal << "'s Constructor called" << std::endl;
    return ;
};

Contact::~Contact(void)
{
    std::cout << "Contact " << Contact::_ordinal << "'s Destructor called" << std::endl;
    Contact::_ordinal -=1;
    return ;
}

void Contact::set_first_name(std::string value)
{
    this->first_name = value;
    return ;
}

void Contact::set_last_name(std::string value)
{
    this->last_name = value;
    return ;
}

void Contact::set_nickname(std::string value)
{
    this->nickname = value;
    return ;
}

void Contact::set_phone_number(std::string value)
{
    this->phone_number = value;
    return ;
}

void Contact::set_darkest_secret(std::string value)
{
    this->darkest_secret = value;
    return ;
}


std::string Contact::get_first_name(void) const
{
    return this->first_name;
}

std::string Contact::get_last_name(void) const
{
    return this->last_name;
}

std::string Contact::get_nickname(void) const
{
    return this->nickname;
}

std::string Contact::get_phone_number(void) const
{
    return this->phone_number;
}

std::string Contact::get_darkest_secret(void) const
{
    return this->darkest_secret;
}

std::string Contact::read_non_empty_string(const std::string prompt)
{
	std::string	text;
	bool		correcto = false;
	

	while (not correcto)
	{
		std::cout << prompt;
        std::getline(std::cin, text, std::cin.widen('\n'));
        if (text.empty())
            std::cout << "Cannot accept empty strings" << std::endl;
		else
            correcto = true;
	}
    return text ;
}

void Contact::view_head(void) const
{
    std::cout << "|1234567890|1234567890|1234567890|1234567890|" << std::endl;
    std::cout << "|  Index   |First name|Last  name|Nickname  |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void Contact::view_short(const int index) const
{
    std::cout << "|" ;
    std::cout << std::setw(10) << index            << "|" ;
    std::cout << std::setw(10) << Contact::truncate_name(this->first_name, 10) << "|";
    std::cout << std::setw(10) << Contact::truncate_name(this->last_name, 10)  << "|" ;
    std::cout << std::setw(10) << Contact::truncate_name(this->nickname, 10)   << "|" << std::endl;
}

void Contact::view_foot(void) const
{
     std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void Contact::view_long(void) const
{
    std::cout << "-------------Contact details -----------" << std::endl;
    std::cout << "First Name     >" << this->first_name << std::endl;
    std::cout << "Last  Name     >" << this->last_name << std::endl;
    std::cout << "Nickname       >" << this->nickname << std::endl;
    std::cout << "Phone Number   >" << this->phone_number << std::endl;
    std::cout << "Darkest Secret >" << this->darkest_secret << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

std::string Contact::truncate_name(std::string data, unsigned long width) const
{
    std::string aux;


    if (data.length() > width)
    {
        aux = data.substr(0, width - 1) + '.';
        return aux;
    }
    return data;
}
