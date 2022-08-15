


enum StateOfElevator{
    isFree,
    isBusy,
    isBlocked,
    isMoving
};

class Elevator{

private:
    int mFloor;


public:
    Elevator(int floor) : mFloor(floor){}
    int incrementFloor();
    int decrementFloor();
    int getFloor();
    StateOfElevator setDestination(int destination);

};

StateOfElevator Elevator::setDestination(int destination){
    mFloor = destination;
    return StateOfElevator::isMoving;
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