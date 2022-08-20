


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
public:
    Elevator(int floor) : mCurrentFloor(floor){
        mState = StateOfElevator::isFree;
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
    return this->mCurrentFloor;
}

int Elevator::getMinFloor(){
    return this->mCurrentFloor;
}

int Elevator::incrementFloor(){
    this->mCurrentFloor++;
    return getFloor();
}

int Elevator::decrementFloor(){
    this->mCurrentFloor--;
    return getFloor();
}