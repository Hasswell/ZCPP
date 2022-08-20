
#include <cassert>

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
    Elevator(int floor) : mCurrentFloor(floor){
        mState = StateOfElevator::isFree;
    }

    Elevator(int minFloor, int maxFloor) : mCurrentFloor(0){
        assert(maxFloor > minFloor);
        mState = StateOfElevator::isFree;
        mMinFloor = minFloor;
        mMaxFloor = maxFloor;
    }
    int incrementFloor();
    int decrementFloor();
    int getFloor();
    int getMinFloor();
    int getMaxFloor();
    StateOfElevator getStatus();
    StateOfElevator setDestination(int destination);

};

StateOfElevator Elevator::setDestination(int destination){
    mCurrentFloor = destination;
    return StateOfElevator::isMoving;
}

StateOfElevator Elevator::getStatus(){
    return this->mState;
}

int Elevator::getFloor(){
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
    return getFloor();
}

int Elevator::decrementFloor(){
    this->mCurrentFloor--;
    return getFloor();
}