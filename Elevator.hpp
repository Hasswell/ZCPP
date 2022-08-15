


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


};