


enum StateOfElevator{
    isFree,
    isBusy,
    isBlocked,
    isMoving
};

class Elevator{

private:
    int mFloor;
    StateOfElevator mState;
public:
    Elevator(int floor) : mFloor(floor){
        mState = StateOfElevator::isFree;
    }
    int incrementFloor();
    int decrementFloor();
    int getFloor();
    StateOfElevator getStatus();
    StateOfElevator setDestination(int destination);

};

StateOfElevator Elevator::setDestination(int destination){
    mFloor = destination;
    return StateOfElevator::isMoving;
}

StateOfElevator Elevator::getStatus(){
    return this->mState;
}


int Elevator::getFloor(){
    return this->mFloor;
}

int Elevator::incrementFloor(){
    this->mFloor++;
    return getFloor();
}

int Elevator::decrementFloor(){
    this->mFloor--;
    return getFloor();
}