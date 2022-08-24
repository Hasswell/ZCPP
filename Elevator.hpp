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
public:
    Elevator(int minFloor, int maxFloor){
        assert(maxFloor > minFloor);
        mState = StateOfElevator::isFree;
        mMinFloor = minFloor;
        mMaxFloor = maxFloor;
        mCurrentFloor = (mMinFloor + mMaxFloor) / 2;
    }
    bool operator==(const Elevator& toCompare)const{
        return  (toCompare.getCurrentFloor() == mCurrentFloor);
    }
    int incrementFloor();
    int decrementFloor();
    int setCurrentFloor(int floor);
    
    int getMinFloor();
    int getMaxFloor();

    //final methods for the interface:
    StateOfElevator getStatus();
    StateOfElevator setDestination(int destination);
    int getCurrentFloor()const;
private:
    //private methods for the checking
    
};

StateOfElevator Elevator::setDestination(int destination){

    this->mState = StateOfElevator::isMoving;
    while(destination != mCurrentFloor){
        if(destination > mCurrentFloor){
            incrementFloor();
        }else{
            decrementFloor();
        }
    }
    return StateOfElevator::isFree;
}

StateOfElevator Elevator::getStatus(){
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
    return getCurrentFloor();
}

int Elevator::decrementFloor(){
    this->mCurrentFloor--;
    return getCurrentFloor();
}


#endif