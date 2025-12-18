#include "Student.h"

// Default Constructor
Student::Student() : User(), id(0) {}

// Parameterized Constructor
Student::Student(const std::string &email, int id) : User(email), id(id) {}

// ID
int Student::getID() const {
    return id;
}

void Student::setID(int id) {
    this->id = id;
}

void Student::displayMenu() const {
    std::cout << "\n======================================" << std::endl;
    std::cout << "        STUDENT RESERVATION MENU      " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Logged in as: " << getEmail() << " (ID: " << id << ")" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "1. List All Available Resources" << std::endl;
    std::cout << "2. Search Resource by Name/ID" << std::endl;
    std::cout << "3. Create a New Reservation" << std::endl;
    std::cout << "4. View My Upcoming Reservations" << std::endl;
    std::cout << "5. Cancel an Existing Reservation" << std::endl;
    std::cout << "0. Logout" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Please select an option: ";
}