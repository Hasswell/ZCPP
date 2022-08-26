#ifndef ELEVATOR_COR_HPP
#define ELEVATOR_COR_HPP

#include "Elevator.hpp"

class Elevator;

class ElevatorCOR{
    public:
    static void CheckElevatorParameters(Elevator& testedElevator){
        // assert(testedElevator.getCurrentFloor() >= testedElevator.getMinFloor());
        // assert(testedElevator.getCurrentFloor() <= testedElevator.getMaxFloor());
    }

};

#endif