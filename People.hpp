#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <cassert>
#include "Logger.hpp"

struct People{
    unsigned int mNumberOfPeople;
    int mDesignatedFloor;
    int mStartingFloor;
public:
    People(unsigned int numberOfPeople, int designatedFloor,int startingFloor){
        assert(numberOfPeople > 0);
        mNumberOfPeople = numberOfPeople;
        mDesignatedFloor = designatedFloor;
        mStartingFloor = startingFloor;
        std::string localMessage = "Group of people has been created, number of people: "\
        + std::to_string(mNumberOfPeople) + ", destination: "
        + std::to_string(mDesignatedFloor) + ", starting floor: " + std::to_string(mStartingFloor);
        logMessage(localMessage);
    }
    People(int numberOfPeople, int designatedFloor,int startingFloor) = delete;
    bool operator==(const People& toCompare)const {
        bool destination = toCompare.mDesignatedFloor == this->mDesignatedFloor;
        bool start = toCompare.mStartingFloor == this->mStartingFloor;
        bool number = toCompare.mNumberOfPeople == this->mNumberOfPeople;
        return (destination && start && number);
    }
    People(const People& toMove) = default;
    People() = default;
    ~People() = default;
};

#endif