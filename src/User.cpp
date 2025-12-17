#include "User.h"

// Default Constructor
User::User() : email(""), username(""), role("Unknown") {}

// Constructor
User::User(const std::string &email, const std::string &username, const std::string &role) 
    : email(email), username(username), role(role) {}

// EMAIL
const std::string &User::getEmail() const {
    return email;
}

void User::setEmail(const std::string &email) {
    this->email = email;
}

// USERNAME
const std::string &User::getUsername() const {
    return username;
}

void User::setUsername(const std::string &username) {
    this->username = username;
}

// ROLE
const std::string &User::getRole() const {
    return role;
}