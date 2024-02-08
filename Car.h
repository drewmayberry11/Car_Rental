#ifndef CAR_H
#define CAR_H

#pragma once

#include <iostream>
#include <iomanip>

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
    float getPricePerDay() const { return pricePerDay; }

    void displayCar()
    {

        const int idWidth = 4;     // Width for the car ID
        const int makeWidth = 12;  // Adjusted width for the car's make
        const int modelWidth = 12; // Adjusted width for the car's model
        const int priceWidth = 4;  // Width for the price, including space for "$"

        std::cout << std::left << std::setw(idWidth) << carID
                  << std::setw(makeWidth) << make
                  << std::setw(modelWidth) << model
                  << "$" << std::right << std::setw(priceWidth - 1) << std::fixed << std::setprecision(2) << pricePerDay << std::endl;
    }

    void displayCarForRental()
    {
        // Assuming make, model, and pricePerDay are accessible in this context
        const int spacing = 4;    // Number of spaces you want before price
        const int priceWidth = 4; // Width for the price, assuming "$" + price. Adjust as necessary

        // Calculate the total width required for make and model based on your desired output
        int makeModelWidth = 20; // Example fixed width for make and model together. Adjust based on your data

        // Print make and model
        std::cout << std::left << std::setw(10) << (make + " " + model);

        // Print the price with a fixed precision of 2 decimal places, preceded by 4 spaces
        std::cout << std::string(spacing, ' ') << "$" << std::right << std::setw(priceWidth) << std::fixed << std::setprecision(2) << pricePerDay << std::endl;
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

#endif