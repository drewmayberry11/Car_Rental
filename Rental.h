#ifndef RENTAL_H
#define RENTAL_H

#include "Customer.h"
#include "Car.h"
#include <iostream>

class Rental
{
public:
    static size_t nextRentalID; // Correct declaration of static member

    Rental(Customer *customer, Car *car, size_t rentDays)
        : customerPtr(customer), carPtr(car), rentalDays(rentDays), isActive(true)
    {
        rentalID = nextRentalID++; // Increment the static ID for each new rental
        calculateCost();           // Calculate the total cost upon creating the rental
    }
    Car *getCar() const { return carPtr; }
    size_t getRentalID() const { return rentalID; }
    void endRental() { isActive = false; }
    float getTotalCost() const { return totalCost; }

    void printRental()
    {
        // Width for "Final Cost:" label

        // Output rental ID
        std::cout << "\nRent ID: " << rentalID << std::endl;

        // Output customer information
        customerPtr->printCustomerForRental();

        // Output car information without modifying displayCar
        carPtr->displayCarForRental();

        // Output total days
        std::cout << "Total days: " << std::setw(5) << rentalDays << std::endl;

        // Output final cost aligned
        std::cout << "Final Cost:" << std::setw(6) << "$" << totalCost << std::endl;
    }

private:
    Customer *customerPtr;
    Car *carPtr;
    size_t rentalID;
    size_t rentalDays;
    bool isActive;
    float totalCost;

    void calculateCost()
    {
        totalCost = carPtr->getPricePerDay() * rentalDays;
    }
};

size_t Rental::nextRentalID = 1; // Correct definition of static member outside the class

#endif // RENTAL_H
