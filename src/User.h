#ifndef USER_H
#define USER_H

#include <string>

class User
{

        private:
                std::string email;

        public:
                User();
                User(const std::string &email);
                const std::string &getEmail() const;
                void setEmail(const std::string &email);

};

#endif
