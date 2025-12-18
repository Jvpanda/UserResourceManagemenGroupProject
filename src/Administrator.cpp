#include "Administrator.h"

// Default Constructor
Administrator::Administrator() : User(), password("admin123") {}

// Parameterized Constructor
Administrator::Administrator(const std::string &email, const std::string &password) 
    : User(email), password(password) {}

// Password
const std::string &Administrator::getPassword() const {
    return password;
}

void Administrator::setPassword(const std::string &password) {
    this->password = password;
}

// menu 
void Administrator::displayMenu() const {
    std::cout << "\n======================================" << std::endl;
    std::cout << "      ADMINISTRATOR CONTROL PANEL     " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Logged in as: " << getEmail() << " (ADMIN)" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "1. Add New Campus Resource" << std::endl;
    std::cout << "2. Remove/Edit Existing Resource" << std::endl;
    std::cout << "3. View All System Reservations" << std::endl;
    std::cout << "4. Generate Resource Usage Report" << std::endl;
    std::cout << "5. System Settings" << std::endl;
    std::cout << "0. Logout" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Please select an administrative action: ";
}