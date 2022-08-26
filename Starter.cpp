#include "Logger.hpp"
#include "QueueOfPerson.hpp"
#include <iostream>
#include "SystemApplication.hpp"

// Logger constLogger("Logs.txt");

int main(){


    std::vector<std::string> idsForElevators = {"0xFFAA","0xDDCC","0xCCDD","0xAABB"};
    const int maxFloor = 10;
    const int minFloor = -10;
    
    PullOfElevators elevators(4,minFloor,maxFloor,idsForElevators);
    QueueOfPersons queueOfPassangers;
    queueOfPassangers.push(People((unsigned int)5,5,0));
    queueOfPassangers.push(People((unsigned int)3,-3,7));
    queueOfPassangers.push(People((unsigned int)2,8,-3));
    queueOfPassangers.push(People((unsigned int)7,7,4));

    SystemApplication systemForElevators(queueOfPassangers,elevators);
    systemForElevators.RunApplication();
  

    return 0;
}