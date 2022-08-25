#ifndef PULL_OF_ELEVATORS_HPP
#define PULL_OF_ELEVATORS_HPP
#include <vector>
#include "Elevator.hpp"
#include "ElevatorFactory.hpp"
#include "People.hpp"
#include "algorithm"
#include <cassert>

class PullOfElevators{
public:
    PullOfElevators(int numberOfElevators,int minFloor, int maxFloor,std::vector<std::string> ids){
        ElevatorFactory factoryForElevators;
        for(int i = 0; i < numberOfElevators;i++){
            pullOfElevators.push_back(factoryForElevators.create(minFloor,maxFloor,ids[i]));
        }
    }
    PullOfElevators(const PullOfElevators& toCopy) = default;
    void setAlarmForElevators(){
        for(auto& elevator : pullOfElevators){
            elevator.setDestination(0);
        }
    }

    void setFloorForElevator(int numberOfElevator,int startingFloor){
        assert(numberOfElevator < pullOfElevators.size());
        assert(pullOfElevators[numberOfElevator].getMaxFloor() >= startingFloor);
        assert(pullOfElevators[numberOfElevator].getMinFloor() <= startingFloor);
        pullOfElevators[numberOfElevator].setCurrentFloor(startingFloor);
    }
    StateOfElevator passPeopleToElevator(People group);
    auto chooseElevator(int destination);
    Elevator& selectElevator(int position){
        assert(position < pullOfElevators.size());
        assert(position >= 0);
        return pullOfElevators[position];
    }

    int calculateDistance(Elevator& elevator,int currentPosition);


private:
    std::vector<Elevator> pullOfElevators;

};


int PullOfElevators::calculateDistance(Elevator& elevator, int currentPosition){
    return abs(currentPosition - elevator.getCurrentFloor()); 
}

auto PullOfElevators::chooseElevator(int currentFloor){
    std::vector<int> distanceVector;
    for(auto& elevator : pullOfElevators){
        distanceVector.push_back(calculateDistance(elevator,currentFloor));
    }

    auto position = std::min_element(distanceVector.begin(),distanceVector.end());
    return (pullOfElevators.begin() + std::distance(distanceVector.begin(),position));
}

StateOfElevator PullOfElevators::passPeopleToElevator(People group){

    //remember -> returns iterator!
    auto selectedElevator = chooseElevator(group.mStartingFloor);
    selectedElevator->setDestination(group.mDesignatedFloor);
    return StateOfElevator::isFree;
}


#endif