#include "CarManager.h"
#include <limits>

void logInPassword()
{
}

int main()
{
    size_t option;
    while (true)
    {
        std::cout << "Mayberry Car Rentals:\n";
        std::cout << "Option one: ";
        std::cout << "Exit: ";

        if (std::cin >> option)
        {
            if (option == 0)
            {
                std::cout << "GooBye" << std::endl;
                break;
            }

            switch (option)
            {
            case 1:
                std::cout << "Option 1 " << std::endl;
            }
        }
    }
    return 0;
}
