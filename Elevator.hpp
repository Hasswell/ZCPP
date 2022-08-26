#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <cassert>
#include <ctime>
#include <random>
#include <iostream>

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
public:
    Elevator(int minFloor, int maxFloor, std::string id){
        assert(maxFloor > minFloor);
        mState = StateOfElevator::isFree;
        mMinFloor = minFloor;
        mMaxFloor = maxFloor;
        mCurrentFloor = (mMinFloor + mMaxFloor) / 2;
        mIdElevator = id;
        std::string localMessage = "Elevator is created. Parameters: " + this->mIdElevator +
        ", max floor: " + std::to_string(this->getMinFloor()) +
        ", max floor: " + std::to_string(this->getMaxFloor()) + 
        ", current floor: " + std::to_string(this->getCurrentFloor()); 
    }
    bool operator==(const Elevator& toCompare)const{
        return  (toCompare.getCurrentFloor() == mCurrentFloor);
    }
    int incrementFloor();
    int decrementFloor();
    int setCurrentFloor(int floor);
    
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

StateOfElevator Elevator::setDestination(int destination){

    std::string localMessage = "Elevator number: " + this->mIdElevator + " is moving to the " + std::to_string(destination) + " floor";

    this->mState = StateOfElevator::isMoving;
    while(destination != mCurrentFloor){
        if(destination > mCurrentFloor){
            incrementFloor();
        }else{
            decrementFloor();
        }
    }

    localMessage = "Current floor of the " + this->mIdElevator + " is: " + std::to_string(this->getCurrentFloor());
    
    return StateOfElevator::isFree;
}

StateOfElevator Elevator::getStatus(){
    std::string localMessage = "State of elevator number: " + this->mIdElevator + " is " + std::to_string(this->mState);
    return this->mState;
}

int Elevator::setCurrentFloor(int floor){
    assert(floor <= mMaxFloor);
    assert(floor >= mMinFloor);
    this->mCurrentFloor = floor;
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
    std::string localMessage = "Elevator number: " + this->mIdElevator + " is  going up, current floor is: " + std::to_string(this->getCurrentFloor());
    return getCurrentFloor();
}

int Elevator::decrementFloor(){
    this->mCurrentFloor--;
    std::string localMessage = "Elevator number: " + this->mIdElevator + " is  going down, current floor is: " + std::to_string(this->getCurrentFloor());
    return getCurrentFloor();
}

std::string Elevator::getId(){
    return this->mIdElevator;
}

#endif