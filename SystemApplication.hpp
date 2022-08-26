#ifndef SYSTEM_APPLICATION_HPP
#define SYSTEM_APPLICATION_HPP
#include "PullOfElevators.hpp"
#include "Logger.hpp"
#include "ElevatorFactory.hpp"
#include "QueueOfPerson.hpp"


class SystemApplication{
public:
    SystemApplication(QueueOfPersons passangers, PullOfElevators elevators) : mElevatorSystems(elevators), mQueueOfPassangers(passangers){
    }
    void RunApplication(){
        while(!mQueueOfPassangers.empty()){
            static int counter = 0;
            std::cout << "Number of evaluations: " << mQueueOfPassangers.size() << std::endl;
            mElevatorSystems.passPeopleToElevator(mQueueOfPassangers.front());
            mQueueOfPassangers.Pop();
        }
    }
    void setAlarmForTheBuilding(){
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