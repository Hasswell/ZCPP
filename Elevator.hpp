


enum StateOfElevator{
    isFree,
    isBusy,
    isBlocked
};

class Elevator{

private:
    int mFloor;

public:
    Elevator(int floor) : mFloor(floor){}
    int incrementFloor();
    int decrementFloor();
    int getFloor();

};


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