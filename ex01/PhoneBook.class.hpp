#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"
# define MAX_CONTACTS 8
class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void add(Contact& one_contac);
		void search(void) const;        
    private:
        Contact list[MAX_CONTACTS];
		int _used;

};

# endif
