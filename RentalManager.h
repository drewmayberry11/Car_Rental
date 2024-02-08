#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#pragma once
#include "Rental.h"
#include <vector>
#include <algorithm>

class RentalManager
{
public:
    void createNewRental(Customer *customer, Car *car, size_t rentDays)
    {
        if (car->getIsAvailable())
        {
            Rental newRental(customer, car, rentDays);
            rentals.push_back(newRental);
            car->setIsAvailable(false);
            totalAmount += newRental.getTotalCost();

            std::cout << "Successfully added a rental.\n";
        }
        else
        {
            std::cout << "Car not available" << std::endl;
        }
    }

    void returnRental(size_t rentalID)
    {
        auto it = std::find_if(rentals.begin(), rentals.end(),
                               [rentalID](const Rental &rental)
                               { return rental.getRentalID() == rentalID; });

        if (it != rentals.end())
        {
            // Mark the car as available again
            it->getCar()->setIsAvailable(true);

            // End the rental
            it->endRental();

            // Move the rental to the history vector
            history.push_back(*it);

            // Remove the rental from the active rentals vector
            rentals.erase(it);

            std::cout << "Rental returned successfully. Moved to history.\n";
        }
        else
        {
            std::cout << "Rental ID not found.\n";
        }
    }

    void displayActiveRentals()
    {
        for (auto &rental : rentals)
        {
            rental.printRental();
            std::cout << "\n";
        }
    }
    void displayRentalHistory()
    {
        for (auto &hist : history)
        {
            hist.printRental();
        }
        std::cout << "Total Revenue:  $" << totalAmount << std::endl;
    }

private:
    std::vector<Rental> rentals;
    std::vector<Rental> history;
    float totalAmount = 0.0;
};

#endif