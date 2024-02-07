#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#pragma once

#include "Customer.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class CustomerManager
{
public:
    CustomerManager() : nextID(1) {}

    void loadCustomersFromFile(const std::string &fileName)
    {
        std::ifstream file(fileName);
        std::string line;

        if (!file.is_open())
        {
            std::cerr << "Error opening customer file" << std::endl;
        }

        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string firstName, lastName, memberStr;
            bool isMember;

            std::getline(ss, firstName, ',');
            std::getline(ss, lastName, ',');
            std::getline(ss, memberStr, ',');

            isMember = (memberStr == "true");

            Customer newCustomer(firstName, lastName, isMember);
            newCustomer.setCustomerID(nextID++);
            customerList.push_back(newCustomer);
        }
    }

    void createCustomer()
    {
        std::string firstName;
        std::string lastName;
        std::cout << "Enter Customers First Name: ";
        std::cin >> firstName;
        std::cout << "Enter Customers Last Name: ";
        std::cin >> lastName;
        Customer newCustomer(firstName, lastName, nextID++);
        customerList.push_back(newCustomer);
    }

    Customer *getCustomerByID(size_t id)
    {
        for (auto &customer : customerList)
        {
            if (id == customer.getCustomerID())
            {
                return &customer; // Return address of the found customer
            }
        }
        return nullptr; // Return nullptr if no customer is found
    }

    void displayAllCustomers()
    {
        for (auto &customer : customerList)
        {
            customer.printCustomer();
        }
    }

private:
    std::vector<Customer> customerList;
    size_t nextID;
};

#endif