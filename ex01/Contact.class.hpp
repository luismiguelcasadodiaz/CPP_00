#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact
{
    public:
        Contact(std::string one_first_name, 
                std::string one_last_name,
                std::string one_nickname,
                std::string one_phone_number,
                std::string one_darkest_secret);
        Contact(void);
        ~Contact(void);
        void set_first_name(std::string value);
        void set_last_name(std::string value);
        void set_nickname(std::string value);
        void set_phone_number(std::string value);
        void set_darkest_secret(std::string value);

        std::string get_first_name(void) const;
        std::string get_last_name(void) const;
        std::string get_nickname(void) const;
        std::string get_phone_number(void) const;
        std::string get_darkest_secret(void) const;

        std::string read_non_empty_string(const std::string prompt);
    private:
        static int _ordinal;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;


};



#endif
