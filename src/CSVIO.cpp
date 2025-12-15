#include "CSVIO.h"
#include "LabEquipment.h"
#include "Resource.h"
#include "SportCourt.h"
#include <fstream>
#include <iostream>
#include <memory>
using namespace std;

void clearAttribute(ifstream &in)
{
        string att;
        getline(in, att, ':');
        in.get();
        return;
}

std::string getStringAttribute(ifstream &in)
{
        std::string value;
        clearAttribute(in);
        getline(in, value);
        return value;
}

int getIntAttribute(ifstream &in)
{
        int num = 0;
        clearAttribute(in);
        in >> num;
        in.ignore(777, '\n');
        return num;
}

template <typename T> std::unique_ptr<T> createResourceFromFile(ifstream &in)
{
        string line;
        int number           = 0;
        std::unique_ptr<T> r = make_unique<T>();

        number = getIntAttribute(in);
        r->setID(number);
        line = getStringAttribute(in);
        r->setName(line);

        clearAttribute(in);
        in >> number;
        r->setBeginningAvailabilityHour(number);
        in.get();
        in >> number;
        r->setBeginningAvailabilityMinute(number);
        in.ignore(777, '\n');

        clearAttribute(in);
        in >> number;
        r->setEndAvailabilityHour(number);
        in.get();
        in >> number;
        r->setEndAvailabilityMinute(number);
        in.ignore(777, '\n');

        number = getIntAttribute(in);
        r->setAvailabilityInterval(number);

        return r;
}

unique_ptr<Reservation> createReservationFromFile(ifstream &in)
{
        string line;
        int num                        = 0;
        std::unique_ptr<Reservation> r = make_unique<Reservation>();

        line = getStringAttribute(in);
        r->setstudentLogin(line);
        clearAttribute(in);

        in >> num;
        r->setbeginningTimeHour(num);
        in.get();
        in >> num;
        r->setbeginningTimeMinute(num);
        in.ignore(777, '\n');

        num = getIntAttribute(in);
        r->setinterval(num);

        return r;
}

void CSVIO::populateResourcesFromList(ResourceManager &rm)
{
        ifstream inFile;
        inFile.open("csvs/Resources.csv");
        string line, attribute, type;
        int num = 0;
        std::unique_ptr<Resource> resource;

        while (inFile.peek() != -1)
        {
                getline(inFile, attribute, ':');
                inFile.get();

                if (attribute == "Resource Type" ||
                    attribute == "\nResource Type")
                {
                        getline(inFile, line);
                        if (line == "SportCourt")
                        {
                                std::unique_ptr<SportCourt> SP = std::move(
                                    createResourceFromFile<SportCourt>(inFile));
                                line = getStringAttribute(inFile);
                                SP->setSportType(line);
                                num = getIntAttribute(inFile);
                                SP->setSeatingCapacity(num);
                                resource = std::move(SP);

                                rm.createResource(std::move(resource));
                        }
                        else if (line == "LabEquipment")
                        {
                                std::unique_ptr<LabEquipment> LE = std::move(
                                    createResourceFromFile<LabEquipment>(
                                        inFile));
                                line = getStringAttribute(inFile);
                                LE->setLabName(line);
                                num = getIntAttribute(inFile);
                                LE->setGroupNumber(num);
                                resource = std::move(LE);

                                rm.createResource(std::move(resource));
                        }
                }
                else if (attribute == "\nReservation")
                {
                        std::unique_ptr<Reservation> res =
                            std::move(createReservationFromFile(inFile));
                        rm.createReservation(rm.ResourceList.back()->getID(),
                                             std::move(res));
                }
        }
        inFile.close();
}

void CSVIO::createResourcesCSV(const ResourceManager &rm)
{
        ofstream outFile;
        outFile.open("csvs/Resources.csv");
        for (auto &r : rm.ResourceList)
        {
                outFile << *r;
                for (auto &res : r->getReservationList())
                {
                        outFile << *res;
                }
        }
        outFile.close();
}
