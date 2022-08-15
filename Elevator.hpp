


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
    return 1;
}

int Elevator::incrementFloor(){
    return 1;
}

int Elevator::decrementFloor(){
    return 1;
}