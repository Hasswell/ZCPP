#ifndef PEOPLE_FACTORY_HPP
#define PEOPLE_FACTORY_HPP

#include "People.hpp"
#include <random>

class PeopleFactory{
    public:
        People create(unsigned int numberOfPeople, int destination,int startFloor);
        People createRandom(int minFloor, int maxFloor);
};

People PeopleFactory::create(unsigned int numberOfPeople, int destination,int startFloor){
    return People(numberOfPeople,destination,startFloor);
}

People PeopleFactory::createRandom(int minFloor, int maxFloor){
    std::random_device randomDevice; 
    const int maxNumberOfPeople = 10;
    std::mt19937 generator(randomDevice()); 
    std::uniform_int_distribution<> distributionForFloors(minFloor, maxFloor); 
    std::uniform_int_distribution<> distributionForPeople(0, maxNumberOfPeople); 
    unsigned int numberOfPeople = (unsigned int)distributionForPeople(generator);
    int destination = distributionForFloors(generator);
    int startFloor = distributionForFloors(generator);
    return create(numberOfPeople,destination,startFloor);
}



#endif