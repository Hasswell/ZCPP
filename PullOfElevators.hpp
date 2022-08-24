#ifndef PULL_OF_ELEVATORS_HPP
#define PULL_OF_ELEVATORS_HPP
#include <vector>
#include "Elevator.hpp"
#include "People.hpp"
#include "algorithm"
#include <cassert>

class PullOfElevators{
public:
    PullOfElevators(int numberOfElevators,int minFloor, int maxFloor){
        for(int i = 0; i < numberOfElevators;i++){
            pullOfElevators.push_back(Elevator(minFloor,maxFloor));
        }
    }

    void setFloorForElevator(int numberOfElevator,int startingFloor){
        assert(numberOfElevator < pullOfElevators.size());
        assert(pullOfElevators[numberOfElevator].getMaxFloor() >= startingFloor);
        assert(pullOfElevators[numberOfElevator].getMinFloor() <= startingFloor);
        pullOfElevators[numberOfElevator].setCurrentFloor(startingFloor);
    }
    StateOfElevator passPeopleToElevator(People group);
    Elevator& chooseElevator(int destination);
    Elevator& selectElevator(int position){
        assert(position < pullOfElevators.size());
        assert(position >= 0);
        return pullOfElevators[position];
    }

    int calculateDistance(Elevator& elevator,int destination);


private:
    std::vector<Elevator> pullOfElevators;

};


int PullOfElevators::calculateDistance(Elevator& elevator, int destination){
    return abs(destination - elevator.getCurrentFloor()); 
}

Elevator& PullOfElevators::chooseElevator(int destination){
    std::vector<int> distanceVector;
    for(auto& x : pullOfElevators){
        distanceVector.push_back(calculateDistance(x,destination));
    }

    auto position = std::min_element(distanceVector.begin(),distanceVector.end());
    return *(pullOfElevators.begin() + std::distance(distanceVector.begin(),position));
}

StateOfElevator passPeopleToElevator(People group){



    return StateOfElevator::isFree;
}


#endif