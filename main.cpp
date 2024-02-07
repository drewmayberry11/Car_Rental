#include "CarManager.h"
#include "CustomerManager.h"
#include "Rental.h"
#include <limits>

bool logInPassword();

int main()
{
    size_t option;
    CustomerManager customerList;
    CarManager carList;
    CustomerManager newCustomer;

    carList.loadCarsFromFile("carList.txt");
    customerList.loadCustomersFromFile("customers.txt");

    while (true)
    {

        std::cout << "\nMayberry Car Rentals:\n";
        std::cout << "2. Add Customer: ";
        std::cout << "1. Rent Car: ";
        std::cout << "0. Exit: ";

        std::cin >> option;

        if (option == 0)
        {
            std::cout << "GoodBye.." << std::endl;
            break;
        }
        else if (option == 1)
        {
            size_t carID;
            size_t customerID;
            size_t rentDays;

            std::cout << "Enter Customer ID: ";
            std::cin >> customerID;
            Customer *customer = customerList.getCustomerByID(customerID);

            std::cout << "Enter Car ID: ";
            std::cin >> carID;
            Car *car = carList.getCarByID(carID);

            std::cout << "How many days of rental: ";
            std::cin >> rentDays;

            if (customer != nullptr && car != nullptr)
            {
                Rental newRental(customer, car, 1);
                newRental.setRentalDays(rentDays);
                newRental.printRental();
            }
        }
        else if (option == 2)
        {

            customerList.createCustomer();
        }

        customerList.displayAllCustomers();
    }
    return 0;
}

bool logInPassword()
{

    std::string inputPassword;
    {
        const std::string correctPassword = "password123";

        std::cout << "Hint: password is 'password123'\n";
        std::cout << "Enter Password: ";
        std::cin >> inputPassword;

        if (inputPassword == correctPassword)
        {
            std::cout << "Correct Password, Welcome!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Incorrect password! use the hint to find password" << std::endl;
            return false;
        }
    }
}