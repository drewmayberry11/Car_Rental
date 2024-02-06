#include <iostream>

class Car
{
public:
    Car() = default;

    Car(size_t carID, const std::string &make, const std::string &model, size_t year)
        : carID(carID), make(make), model(model), year(year), licensePlate(""), pricePerDay(0.0f),
          mileage(0), category("Standard"), isAvailable(true) {}

    void displayCar()
    {
        std::cout << "Car Details:\n";
        std::cout << "ID: " << carID << std::endl;
        std::cout << "Make: " << make << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "License Plate: " << licensePlate << std::endl;
        std::cout << "Price Per Day: $" << pricePerDay << std::endl;
        std::cout << "Mileage: " << mileage << " miles" << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }

private:
    size_t carID;
    std::string make;
    std::string model;
    size_t year;
    std::string licensePlate;
    float pricePerDay;
    long int mileage;
    std::string category;
    bool isAvailable;
};

int main()
{
    Car newCar(1, "Jeep", "Cherokee", 2017);
    newCar.displayCar();
}