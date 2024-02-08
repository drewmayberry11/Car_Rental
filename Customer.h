#ifndef CUSTOMER_H
#define CUSTOMER_H

#pragma once
#include <iostream>
#include <iomanip>
class Customer
{
public:
    Customer() = default;

    Customer(std::string firstN, std::string lastN, bool member)
        : firstName(firstN), lastName(lastN), isMember(member) {}

    void setCustomerID(const size_t custID) { customerID = custID; }

    size_t getCustomerID() const { return customerID; }

    void printCustomer()
    {
        const int idWidth = 5;    // Adjust based on the maximum expected length of customerID
        const int nameWidth = 20; // Adjust based on the maximum expected length of names

        // Use std::left to align text to the left
        std::cout << std::left << std::setw(idWidth) << customerID << std::setw(nameWidth) << (firstName + " " + lastName) << std::endl;
    }

    void printCustomerForRental()
    {
        std::cout << firstName << "  " << lastName << std::endl;
    }

private:
    size_t customerID;
    std::string firstName;
    std::string lastName;
    bool isMember;
};

#endif