// Ananda Guha 4388153
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>

Car::Car() {
    manufacturer = NULL;
    model = NULL;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    seatCount = 0;
    backseatDoors = 'None';
}
Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign){
    manufacturer = manufacturerName;
    model = modelName;
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    seatCount = numSeats;
    backseatDoors = backseatDoorDesign;
}
Car::Car(Car const& o){
    manufacturer = o.manufacturer;
    model = o.model;
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    seatCount = o.seatCount;
    backseatDoors = o.backseatDoorDesign;
}

Car& Car::operator=(Car const& o){
    this -> model = o.model;
    this -> zeroToSixtyNs = o.zeroToSixtyNs;
    this -> headonDragCoeff = o.headonDragCoeff;
    this -> horsepower = o.horsepower;
    this -> seatCount = o.seatCount;
    this -> backseatDoors = o.backseatDoorDesign;
    return *this;
}

Car::~Car(){
    cout<< "I am destorying the car.";
}

char const* Car::getManufacturer() const {
    return manufacturer;
}

char const* Car::getModel() const{
    return model;
}

PerformanceStats Car::getStats() const{
    return PerformanceStats(horsepower, zeroToSixtyNs, headonDragCoeff)//idk
}

uint8_t Car::getSeatCount() const{
    return seatCount;
}

DoorKind Car::getBackseatDoors() const{
    return backseatDoors
}

void Car::manufacturerChange(char const* const newManufacturer){
    manufacturer = newManufacturer;
}

void Car::modelNameChange(char const* const newModelName){
    model = newModelName;
}

void Car::reevaluateStats(PerformanceStats newStats){
    horsepower = newStats.horsepower;
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
}

void Car::recountSeats(uint8_t newSeatCount){
    seatCount = newSeatCount;
}

void Car::reexamineDoors(DoorKind newDoorKind){
    backseatDoors = newDoorKind;
}