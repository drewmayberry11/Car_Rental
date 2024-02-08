#include "CarManager.h"
#include "CustomerManager.h"
#include "RentalManager.h"
#include <limits>
#include <iomanip>
bool logInPassword();

int main()
{
    size_t option;
    CustomerManager customerList;
    CarManager carList;
    CustomerManager newCustomer;
    std::vector<Rental> activeRentals;
    std::vector<Rental> rentalHistory;
    RentalManager rentalsManager;

    carList.loadCarsFromFile("carList.txt");
    customerList.loadCustomersFromFile("customers.txt");

    while (true)
    {

        const int optionWidth = 3;        // Adjust based on the widest option number
        const std::string separator = ""; // Separator between option number and description

        std::cout << "\nMAYBERRY CAR RENTALS" << std::endl;
        std::cout << std::left << std::setw(optionWidth) << "0" << separator << "Exit" << std::endl;
        std::cout << std::setw(optionWidth) << "1" << separator << "Rent A Car" << std::endl;
        std::cout << std::setw(optionWidth) << "2" << separator << "Create Customer" << std::endl;
        std::cout << std::setw(optionWidth) << "3" << separator << "Display Active Rentals" << std::endl;
        std::cout << std::setw(optionWidth) << "4" << separator << "Return Car" << std::endl;
        std::cout << std::setw(optionWidth) << "5" << separator << "Rental History" << std::endl;
        std::cout << std::setw(optionWidth) << "6" << separator << "Customer List" << std::endl;
        std::cout << std::setw(optionWidth) << "7" << separator << "Full Car List" << std::endl;
        std::cout << "Enter number: ";
        std::cin >>
            option;
        if (option <= 7 && option >= 0)
        {

            if (option == 0)
            {
                std::cout << "GoodBye.." << std::endl;
                break;
            }
            else if (option == 1)
            {
                size_t customerID, carID, rentDays;

                std::cout << "\nCreate New Rental\n"
                          << std::endl;
                customerList.displayAllCustomers();
                std::cout << "Choose Customer ID from above: ";
                std::cin >> customerID;
                Customer *customer = customerList.getCustomerByID(customerID); // Correctly retrieve Customer pointer

                // Display all cars and prompt for selection
                carList.displayAvailableCars(); // Assuming this method exists and shows only available cars
                std::cout << "Enter car ID: ";
                std::cin >> carID;
                Car *car = carList.getCarByID(carID); // Correctly retrieve Car pointer

                // Prompt for rental days
                std::cout << "Enter number of rental days: ";
                std::cin >> rentDays;

                // Check for valid inputs and car availability
                if (customer != nullptr && car != nullptr && car->getIsAvailable())
                {
                    rentalsManager.createNewRental(customer, car, rentDays);
                }
                else
                {
                    std::cout << "Invalid customer ID, car ID, or car not available.\n";
                }
            }

            else if (option == 2)
            {

                customerList.createCustomer();
            }

            if (option == 3)
            {
                std::cout << "Active Rentals;" << std::endl;
                rentalsManager.displayActiveRentals();
            }
            if (option == 4)
            {
                size_t rentalID;
                std::cout << "\nReturn Rental: \n";
                std::cout << "Enter The rental ID: ";
                std::cin >> rentalID;
                rentalsManager.returnRental(rentalID);
            }
            if (option == 5)
            {
                std::cout << "\nDisplay History:" << std::endl;
                rentalsManager.displayRentalHistory();
            }
            if (option == 6)
            {
                std::cout << "\nCustomer List:\n"
                          << std::endl;
                customerList.displayAllCustomers();
            }
            if (option == 7)
            {
                std::cout << "\nFull Car List:\n";
                carList.displayCar();
            }
        }
        else
        {
            std::cout << "Invalid option!!" << std::endl;
        }
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