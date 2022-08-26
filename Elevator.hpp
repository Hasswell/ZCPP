#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <cassert>
#include <ctime>
#include <random>
#include <iostream>
#include "ElevatorCOR.hpp"
#include "Logger.hpp"

enum StateOfElevator{
    isFree,
    isBusy,
    isBlocked,
    isMoving
};


class Elevator{

private:
    int mCurrentFloor;
    StateOfElevator mState;
    int mMinFloor;
    int mMaxFloor;
    std::string mIdElevator;
    unsigned int mNumberOfPeopleTransported;
public:
    Elevator(int minFloor, int maxFloor, std::string id){
        assert(maxFloor > minFloor);
        mState = StateOfElevator::isFree;
        mMinFloor = minFloor;
        mMaxFloor = maxFloor;
        mCurrentFloor = (mMinFloor + mMaxFloor) / 2;
        mIdElevator = id;
        mNumberOfPeopleTransported = 0;
        std::string localMessage = "Elevator is created. Parameters: " + this->mIdElevator +
        ", max floor: " + std::to_string(this->getMinFloor()) +
        ", max floor: " + std::to_string(this->getMaxFloor()) + 
        ", current floor: " + std::to_string(this->getCurrentFloor()); 
        logMessage(localMessage);
    }
    ~Elevator(){
         std::string localMessage = "The elevator: " + this->getId() + " is at " + std::to_string(this->getCurrentFloor()) + " and transported "
         + std::to_string(this->mNumberOfPeopleTransported) + " people";
        logMessage(localMessage);
    }
    bool operator==(const Elevator& toCompare)const{
        return  (toCompare.getCurrentFloor() == mCurrentFloor);
    }
    int incrementFloor();
    int decrementFloor();
    int setCurrentFloor(int floor);
    int addPeople(unsigned int peopleNumber);
    
    int getMinFloor();
    int getMaxFloor();
    std::string getId();

    //final methods for the interface:
    StateOfElevator getStatus();
    StateOfElevator setDestination(int destination);
    int getCurrentFloor()const;
private:
    //private methods for the checking
    
};

static void CheckElevatorParameters(Elevator& testedElevator){
    assert(testedElevator.getCurrentFloor() >= testedElevator.getMinFloor());
    assert(testedElevator.getCurrentFloor() <= testedElevator.getMaxFloor());
    assert(testedElevator.getStatus() != StateOfElevator::isBlocked);
    assert(testedElevator.getStatus() != StateOfElevator::isBusy);
}


int Elevator::addPeople(unsigned int peopleNumber){
    this->mNumberOfPeopleTransported += peopleNumber;
    return this->mNumberOfPeopleTransported;
}

StateOfElevator Elevator::setDestination(int destination){

    std::string localMessage = "Elevator number: " + this->mIdElevator + " is moving to the " + std::to_string(destination) + " floor";
    logMessage(localMessage);
    this->mState = StateOfElevator::isMoving;
    while(destination != mCurrentFloor){
        if(destination > mCurrentFloor){
            incrementFloor();
        }else{
            decrementFloor();
        }
    }

    localMessage = "Current floor of the " + this->mIdElevator + " is: " + std::to_string(this->getCurrentFloor());
    logMessage(localMessage);
    return StateOfElevator::isFree;
}

StateOfElevator Elevator::getStatus(){
    std::string localMessage = "State of elevator number: " + this->mIdElevator + " is " + std::to_string(this->mState);
    logMessage(localMessage);
    return this->mState;
}

int Elevator::setCurrentFloor(int floor){
    this->mCurrentFloor = floor;
    CheckElevatorParameters(*this);
    return this->mCurrentFloor;
}

int Elevator::getCurrentFloor()const{
    return this->mCurrentFloor;
}


int Elevator::getMaxFloor(){
    return this->mMaxFloor;
}

int Elevator::getMinFloor(){
    return this->mMinFloor;
}

int Elevator::incrementFloor(){
    this->mCurrentFloor++;
    CheckElevatorParameters(*this);
    std::string localMessage = "Elevator number: " + this->mIdElevator + " is  going up, current floor is: " + std::to_string(this->getCurrentFloor());
    logMessage(localMessage);
    return getCurrentFloor();
}

int Elevator::decrementFloor(){
    this->mCurrentFloor--;
    CheckElevatorParameters(*this);
    std::string localMessage = "Elevator number: " + this->mIdElevator + " is  going down, current floor is: " + std::to_string(this->getCurrentFloor());
    logMessage(localMessage);
    return getCurrentFloor();
}

std::string Elevator::getId(){
    return this->mIdElevator;
}

#endif