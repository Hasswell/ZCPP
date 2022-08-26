#include "Logger.hpp"
#include "QueueOfPerson.hpp"
#include <iostream>
#include "SystemApplication.hpp"
#include "PeopleFactory.hpp"

// Logger constLogger("Logs.txt");

int main(){


    std::vector<std::string> idsForElevators = {"0xFFAA","0xDDCC","0xCCDD","0xAABB"};
    const int minFloor = -10;
    const int maxFloor = 10;
    unsigned int numberOfGroups = 7;

    SystemApplication systemForElevators(numberOfGroups,idsForElevators,minFloor,maxFloor);
    systemForElevators.RunApplication();
    systemForElevators.setAlarmForTheBuilding();

    return 0;
}