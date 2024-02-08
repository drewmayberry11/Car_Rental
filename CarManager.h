#ifndef CARMANAGER_H
#define CARMANAGER_H

#pragma once

#include "Car.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CarManager
{
public:
    CarManager() = default;

    void loadCarsFromFile(const std::string &fileName)
    {
        std::ifstream file(fileName);
        std::string line;

        if (!file.is_open())
        {
            std::cerr << "Failed to open file" << std::endl;
        }

        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::vector<std::string> tokens;
            std::string token;

            while (std::getline(ss, token, ','))
            {
                tokens.push_back(token);
            }

            if (tokens.size() == 9)
            {
                try
                {

                    size_t carID = std::stoull(tokens[0]);
                    const std::string &make = tokens[1];
                    const std::string &model = tokens[2];
                    size_t year = std::stoull(tokens[3]);
                    std::string licensePlate = tokens[4];
                    float pricePerDay = std::stof(tokens[5]);
                    long mileage = std::stol(tokens[6]);
                    std::string category = tokens[7];
                    bool isAvailable = tokens[8] == "true";

                    Car car(carID, make, model, year);
                    car.setLicensePlate(licensePlate);
                    car.setPricePerDay(pricePerDay);
                    car.setMileage(mileage);
                    car.setCategory(category);
                    car.setIsAvailable(isAvailable);

                    carList.push_back(car);
                }
                catch (const std::exception &e)
                {
                    std::cerr << "Error Processing Line " << line << "\n"
                              << e.what() << std::endl;
                }
            }
            else
            {
                std::cerr << "Unexpected number of attributes in line: " << line << std::endl;
            }
        }
        file.close();
    }

    Car *getCarByID(size_t id)
    {
        for (auto &car : carList)
        {
            if (car.getCarID() == id)
            {
                return &car;
            }
        }
        return nullptr;
    }

    void displayCar()
    {

        for (auto &car : carList)
        {
            car.displayCar();
        }
    }

    void displayALlCars()
    {
        for (auto &car : carList)
        {
            car.displayCar();
        }
    }

    void displayAvailableCars()
    {
        for (auto &car : carList)
        {
            if (car.getIsAvailable() == true)
            {
                car.displayCar();
            }
        }
    }

private:
    std::vector<Car> carList;
};

#endif