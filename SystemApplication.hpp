#ifndef SYSTEM_APPLICATION_HPP
#define SYSTEM_APPLICATION_HPP
#include "PullOfElevators.hpp"
#include "Logger.hpp"
#include "ElevatorFactory.hpp"
#include "QueueOfPerson.hpp"
#include "PeopleFactory.hpp"
#include "Logger.hpp"


class SystemApplication{
public:
    SystemApplication(QueueOfPersons passangers, PullOfElevators elevators) : mElevatorSystems(elevators), mQueueOfPassangers(passangers){
    }
    void RunApplication(){
        while(!mQueueOfPassangers.empty()){
            mElevatorSystems.passPeopleToElevator(mQueueOfPassangers.front());
            mQueueOfPassangers.Pop();
        }
    }
    SystemApplication(unsigned int numberOfGroups,std::vector<std::string> elevators, int minFloor, int maxFloor)
        : mElevatorSystems(PullOfElevators(minFloor,maxFloor,elevators)){

        //random Number Of People
        PeopleFactory peopleFactory;
        for(int i = 0;i<numberOfGroups;i++){
            mQueueOfPassangers.push(peopleFactory.createRandom(minFloor,maxFloor));
        }
    }
    void setAlarmForTheBuilding(){
        std::string localMessage = "The alarm for the building has been announced!";
        logMessage(localMessage);
        mElevatorSystems.setAlarmForElevators();
    }
    void addGroupdOfPeople(){
        mQueueOfPassangers.push(currentGroup);
    }
    void addNumberOfPeople(unsigned int numberOfPeople){
        currentGroup.mNumberOfPeople = numberOfPeople;
    }
    void addDesignatedFloor(int designatedFloor){   
        currentGroup.mDesignatedFloor = designatedFloor;
        
    }
    void addStartingFloor(int startingFloor){
        currentGroup.mStartingFloor = startingFloor;
    }
    int putFloorToElevator(int numberOfElevator){
        return mElevatorSystems.selectElevator(numberOfElevator).getCurrentFloor();
    }
    std::string putDescriptionForTheElevator(int numberOfElevator){
        return mElevatorSystems.selectElevator(numberOfElevator).getId();
    }

private:
    QueueOfPersons mQueueOfPassangers;
    PullOfElevators mElevatorSystems;
    People currentGroup;
};


#endif