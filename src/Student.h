#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <iostream>

class Student : public User
{
    private:
        int id;

    public:
        Student();
        Student(const std::string &email, int id);
        
        int getID() const;
        void setID(int id);

        void displayMenu() const override;
};

#endif