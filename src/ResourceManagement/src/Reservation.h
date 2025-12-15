#ifndef RESERVATION_H
#define RESERVATION_H

#include <ostream>
#include <string>

class Reservation
{
        public:
                Reservation(const std::string astudentLogin,
                            const int beginningTimeHour,
                            const int abeginningTimeMinute,
                            const int ainterval);
                Reservation();
                ~Reservation();

                // Getters
                std::string getstudentLogin() const;
                int getbeginningTimeHour() const;
                int getbeginningTimeMinute() const;
                int getinterval() const;

                // Setters
                void setstudentLogin(std::string astudentLogin);
                void setbeginningTimeHour(int abeginningTimeHour);
                void setbeginningTimeMinute(int abeginningTimeMinute);
                void setinterval(int ainterval);

                void printReservation(std::ostream &os);
                friend std::ostream &operator<<(std::ostream &os,
                                                Reservation &reservation);

        private:
                std::string studentLogin;
                int beginningTimeHour;
                int beginningTimeMinute;
                int interval;
};

#endif
