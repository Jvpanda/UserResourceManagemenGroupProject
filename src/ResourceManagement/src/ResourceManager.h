#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "Resource.h"
#include <memory>
#include <vector>

class ResourceManager
{
        public:
                ResourceManager();
                ~ResourceManager();

                void createReservation(const int id,
                                       std::unique_ptr<Reservation> obj);
                Reservation *getReservation(const int id,
                                            const int reservationTimeHour,
                                            const int reservationTimeMinute);
                void
                updateReservation(const int id, const int reservationTimeHour,
                                  const int reservationTimeMinute,
                                  std::unique_ptr<Reservation> reservation);
                void deleteReservation(const int id,
                                       const int reservationTimeHour,
                                       const int reservationTimeMinute);

                void createResource(std::unique_ptr<Resource> obj);
                Resource *getResource(int id);
                void updateResource(const int id,
                                    std::unique_ptr<Resource> newObj);
                void deleteResource(const int id);

                void listResources();
                void listActiveReservations(const int id);

                std::vector<std::unique_ptr<Resource>> ResourceList;

        private:
};

#endif
