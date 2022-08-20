
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
    if(this->mCurrentFloor + 1 > mMaxFloor){
        return getFloor();
    }
    this->mCurrentFloor++;
    return getFloor();
}

int Elevator::decrementFloor(){
    if(this->mCurrentFloor -1 < mMinFloor){
        return getFloor();
    }
    this->mCurrentFloor--;
    return getFloor();
}