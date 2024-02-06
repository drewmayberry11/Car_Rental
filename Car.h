#include <iostream>

class Car
{
public:
    Car() = default;

    Car(size_t carID, const std::string &make, const std::string &model, size_t year)
        : carID(carID), make(make), model(model), year(year), licensePlate(""), pricePerDay(0.0f),
          mileage(0), category("Standard"), isAvailable(true) {}

    // Setters
    void setCarID(size_t id) { carID = id; }
    void setMake(const std::string &m) { make = m; }
    void setModel(const std::string &m) { model = m; }
    void setYear(size_t y) { year = y; }
    void setLicensePlate(const std::string &licenseP) { licensePlate = licenseP; }
    void setPricePerDay(float ppd) { pricePerDay = ppd; }
    void setMileage(long int m) { mileage = m; }
    void setCategory(const std::string &c) { category = c; }
    void setIsAvailable(bool available) { isAvailable = available; }

    // Getters
    size_t getCarID() const { return carID; }
    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    size_t getYear() const { return year; }
    std::string getLicensePlate() const { return licensePlate; }
    long int getMileage() const { return mileage; }
    std::string getCategory() const { return category; }
    bool getIsAvailable() const { return isAvailable; }

    void displayCar()
    {

        std::cout << "ID: " << carID << ", Make: " << make << ", Model: " << model << std::endl;
        std::cout << "Price per Day: $" << pricePerDay << "In Stock: " << std::boolalpha << isAvailable << std::endl;
    }

    void displayMakeModel()
    {
        std::cout << make << " " << model << std::endl;
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
