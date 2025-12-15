#include "CSVIO.h"
#include "UserInterface.h"
#include <LabEquipment.h>
#include <ResourceManager.h>
#include <SportCourt.h>
#include <iostream>
#include <memory>
using namespace std;

void testResourceStuff()
{
        ResourceManager rm;
        // Example
        // Add test
        std::unique_ptr<SportCourt> d = std::make_unique<SportCourt>(
            1, "SquidwardTennisBalls", 12, 12, 12, 12, 10, "SportSport", 11);
        // Convert to unique_ptr<Base>
        std::unique_ptr<Resource> obj = std::move(d);
        // You must use std::move() because that's how it transfers ownsership
        rm.createResource(std::move(obj));

        // Effectively rm.readResource returns a pointer to a resource that you
        // can then cast into a different pointer for polymorphism

        cout << "Resource Read Test:\n" << (*(SportCourt *)rm.getResource(1));

        // Update Test
        cout << "Resource Update Test:\n";
        rm.updateResource(1, std::make_unique<LabEquipment>(
                                 2, "WenisTester", 10, 12, 22, 10, 20,
                                 "South East Lab of East South", 12));

        // List Test
        cout << "Listing Resources:\n";
        rm.listResources();

        // Same stuff with reservations
        // Add test
        std::unique_ptr<Reservation> res =
            std::make_unique<Reservation>("Student 1", 10, 15, 30);
        rm.createReservation(2, std::move(res));

        // Read Test
        cout << "Reservation Read Test:\n" << *rm.getReservation(2, 10, 15);

        // Update test
        std::unique_ptr<Reservation> res2 =
            std::make_unique<Reservation>("Bob the Builder", 4, 20, 69);
        rm.updateReservation(2, 10, 15, std::move(res2));

        // List Test
        cout << "Reservation List Test:\n";
        rm.listActiveReservations(2);

        // Delete Tests
        cout << "DELETING RESERVATION:\n";
        rm.deleteReservation(2, 4, 20);
        cout << "LISTING RESERVATIONS:\n";
        rm.listActiveReservations(2);

        cout << "DELETING RESOURCE:\n";
        rm.deleteResource(2);
        cout << "LISTING RESOURCES:\n";
        rm.listResources();
}
void testCSVStuff()
{
        ResourceManager rm;

        cout << "CSV TEST\n";
        CSVIO csv;
        // csv.createResourcesCSV(rm);
        csv.populateResourcesFromList(rm);
        rm.listResources();
        rm.listActiveReservations(2);
}

int main()
{
        UserInterface ui;
        ui.run();
        // testResourceStuff();
        // testCSVStuff();
        return 0;
}
