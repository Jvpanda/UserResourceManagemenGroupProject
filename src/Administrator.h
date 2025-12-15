#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"

class Administrator : public User
{

        private:
                std::string password;

        public:
                Administrator();
                Administrator(const std::string &email, const std::string &password);
                const std::string &getPassword() const;
                void setPassword(const std::string &password);
};

#endif
