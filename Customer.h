#ifndef CUSTOMER_H
#define CUSTOMER_H

#pragma once
#include <iostream>

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
        std::cout << firstName << ", " << lastName << std::endl;
    }

private:
    size_t customerID;
    std::string firstName;
    std::string lastName;
    bool isMember;
};

#endif