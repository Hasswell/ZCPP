#ifndef PULL_OF_ELEVATORS_HPP
#define PULL_OF_ELEVATORS_HPP
#include <vector>
#include "Elevator.hpp"
#include "People.hpp"

class PullOfElevators{
public:
    StateOfElevator passPeopleToElevator(People group);
    Elevator& chooseElevator() const;

    int calculateDistance(Elevator& elevator,int destination);


private:
    std::vector<Elevator> pullOfElevators;

};


int PullOfElevators::calculateDistance(Elevator& elevator, int destination){
    return abs(destination - elevator.getCurrentFloor()); 
}


#endif