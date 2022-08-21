#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <cassert>
#include <ctime>
#include <random>

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
    int incrementFloor();
    int decrementFloor();
    int setCurrentFloor(int floor);
    
    int getMinFloor();
    int getMaxFloor();

    //final methods for the interface:
    StateOfElevator getStatus();
    StateOfElevator setDestination(int destination);
    int getCurrentFloor();
private:
    //private methods for the checking
    
};

StateOfElevator Elevator::setDestination(int destination){
    this->mState = StateOfElevator::isMoving;
    mCurrentFloor = destination;
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

int Elevator::getCurrentFloor(){
    return this->mCurrentFloor;
}


int Elevator::getMaxFloor(){
    return this->mMaxFloor;
}

int Elevator::getMinFloor(){
    return this->mMinFloor;
}

int Elevator::incrementFloor(){
    if(this->mCurrentFloor + 1 > mMaxFloor){
        return getCurrentFloor();
    }
    this->mCurrentFloor++;
    return getCurrentFloor();
}

int Elevator::decrementFloor(){
    if(this->mCurrentFloor -1 < mMinFloor){
        return getCurrentFloor();
    }
    this->mCurrentFloor--;
    return getCurrentFloor();
}


#endif