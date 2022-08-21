#ifndef ELEVATOR_FACTORY_HPP
#define ELEVATOR_FACTORY_HPP


class ElevatorFactory{
    public:
        Elevator create(int minFloor, int maxFloor);
};

Elevator ElevatorFactory::create(int minFloor, int maxFloor){
    return Elevator(minFloor,maxFloor);
}



#endif