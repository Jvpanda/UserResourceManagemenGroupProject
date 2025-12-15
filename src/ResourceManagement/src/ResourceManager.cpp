#include "ResourceManager.h"
#include <iostream>
#include <memory>
using namespace std;

ResourceManager::ResourceManager()
{
        ResourceList.reserve(4);
}

ResourceManager::~ResourceManager()
{
}

// Reservation CRUD

void ResourceManager::createReservation(const int id,
                                        std::unique_ptr<Reservation> obj)
{
        for (auto &r : ResourceList)
        {
                if (r->getID() == id)
                {
                        r->getMutableReservationList().push_back(
                            std::move(obj));
                        return;
                }
        }
}

Reservation *ResourceManager::getReservation(const int id,
                                             const int reservationTimeHour,
                                             const int reservationTimeMinute)
{
        for (auto &r : ResourceList)
        {
                if (r->getID() == id)
                {
                        for (auto &res : r->getReservationList())
                        {
                                if (res->getbeginningTimeHour() ==
                                        reservationTimeHour &&
                                    res->getbeginningTimeMinute() ==
                                        reservationTimeMinute) {
                                        return res.get();
                                }
                                return nullptr;
                        }
                }
        }
        return nullptr;
}

void ResourceManager::updateReservation(
    const int id, const int reservationTimeHour,
    const int reservationTimeMinute, std::unique_ptr<Reservation> reservation)
{
        for (auto &r : ResourceList)
        {
                if (r->getID() == id)
                {
                        for (auto &res : r->getMutableReservationList())
                        {
                                res = std::move(reservation);
                                return;
                        }
                }
        }
}

void ResourceManager::deleteReservation(const int id,
                                        const int reservationTimeHour,
                                        const int reservationTimeMinute)
{
        for (auto &r : ResourceList)
        {
                if (r->getID() == id)
                {
                        for (auto iterator = r->getReservationList().begin();
                             iterator != r->getReservationList().end();
                             ++iterator)
                        {
                                r->getMutableReservationList().erase(iterator);
                                return;
                        }
                }
        }
}

// Resource CRUD

void ResourceManager::createResource(std::unique_ptr<Resource> obj)
{
        ResourceList.push_back(std::move(obj));
}

Resource *ResourceManager::getResource(int id)
{
        for (auto &r : ResourceList)
                if (r->getID() == id)
                        return r.get();
        return nullptr;
}

void ResourceManager::updateResource(const int id,
                                     std::unique_ptr<Resource> newObj)
{
        for (auto &r : ResourceList)
        {
                if (r->getID() == id)
                {
                        r = std::move(newObj);
                        return;
                }
        }
}

void ResourceManager::deleteResource(const int id)
{
        for (auto iterator = ResourceList.begin();
             iterator != ResourceList.end(); ++iterator)
        {
                if ((*iterator)->getID() == id)
                {
                        ResourceList.erase(iterator);
                        return;
                }
        }
}

// Extra commands
void ResourceManager::listResources()
{
        for (auto &r : ResourceList)
        {
                cout << *r;
        }
}

void ResourceManager::listActiveReservations(const int id)
{
        for (auto &r : ResourceList)
        {
                if (r->getID() == id)
                {
                        r->PrintReservationList(cout);
                }
        }
}
