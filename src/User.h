#ifndef USER_H
#define USER_H

#include <string>

class User {
        protected: 
                std::string email;
                std::string username;

        public:
                User();
                User(const std::string &email, const std::string &username);
                
                virtual ~User() {}

                const std::string &getEmail() const;
                void setEmail(const std::string &email);
                
                const std::string &getUsername() const;
                void setUsername(const std::string &username);

                virtual void displayMenu() const = 0; 
};

#endif