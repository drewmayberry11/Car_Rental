#ifndef RENTAL_H
#define RENTAL_H

#pragma once

#include "Customer.h"
#include "Car.h"
class Rental
{
public:
    Rental() = default;

    Rental(Customer *customer, Car *car, size_t rentID)
        : customerPtr(customer), carPtr(car), rentalID(rentID), isActive(true) {}

    void setRentalDays(const size_t days) { rentalDays = days; }

    void printRental()
    {
        customerPtr->printCustomer();
        carPtr->displayCar();
    }

private:
    Customer *customerPtr;
    Car *carPtr;
    size_t rentalID;
    size_t rentalDays;
    bool isActive;
};

#endif