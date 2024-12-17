#include <iostream>
#include "Contact.hpp"

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
    std::cout << "Contact's Constructor called" << std::endl;
    return ;
};

Contact::Contact(void)
{
    std::cout << "Contact's Constructor called" << std::endl;
    return ;
};

Contact::~Contact(void)
{
    std::cout << "Contact's Destructor called" << std::endl;
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
