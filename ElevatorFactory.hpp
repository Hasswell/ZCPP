#ifndef ELEVATOR_FACTORY_HPP
#define ELEVATOR_FACTORY_HPP


class ElevatorFactory{
    public:
        Elevator create(int minFloor, int maxFloor,std::string id);
};

Elevator ElevatorFactory::create(int minFloor, int maxFloor,std::string id){
    return Elevator(minFloor,maxFloor,id);
}



#endif