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
    PullOfElevators(int minFloor, int maxFloor,std::vector<std::string> ids){
        ElevatorFactory factoryForElevators;
        for(int i = 0; i < ids.size();i++){
            mPullOfElevators.push_back(factoryForElevators.create(minFloor,maxFloor,ids[i]));
        }
    }
    PullOfElevators(const PullOfElevators& toCopy) = default;
    void setAlarmForElevators(){
        for(auto& elevator : mPullOfElevators){
            elevator.setDestination(0);
        }
    }

    void setFloorForElevator(int numberOfElevator,int startingFloor){
        assert(numberOfElevator < mPullOfElevators.size());
        assert(mPullOfElevators[numberOfElevator].getMaxFloor() >= startingFloor);
        assert(mPullOfElevators[numberOfElevator].getMinFloor() <= startingFloor);
        mPullOfElevators[numberOfElevator].setCurrentFloor(startingFloor);
    }
    StateOfElevator passPeopleToElevator(People group);
    auto chooseElevator(int destination);
    Elevator& selectElevator(int position){
        assert(position < mPullOfElevators.size());
        assert(position >= 0);
        return mPullOfElevators[position];
    }

    int calculateDistance(Elevator& elevator,int currentPosition);


private:
    std::vector<Elevator> mPullOfElevators;

};


int PullOfElevators::calculateDistance(Elevator& elevator, int currentPosition){
    return abs(currentPosition - elevator.getCurrentFloor()); 
}

auto PullOfElevators::chooseElevator(int currentFloor){
    std::vector<int> distanceVector;
    for(auto& elevator : mPullOfElevators){
        distanceVector.push_back(calculateDistance(elevator,currentFloor));
    }
    auto position = std::min_element(distanceVector.begin(),distanceVector.end());
    return (mPullOfElevators.begin() + std::distance(distanceVector.begin(),position));
}

StateOfElevator PullOfElevators::passPeopleToElevator(People group){

    //remember -> returns iterator!
    auto selectedElevator = chooseElevator(group.mStartingFloor);
    selectedElevator->setDestination(group.mDesignatedFloor);
    selectedElevator->addPeople(group.mNumberOfPeople);

    return StateOfElevator::isFree;
}


#endif