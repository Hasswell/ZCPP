#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include <cassert>

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
    }
    People(int numberOfPeople, int designatedFloor,int startingFloor) = delete;
    bool operator==(const People& toCompare)const {
        bool destination = toCompare.mDesignatedFloor == this->mDesignatedFloor;
        bool start = toCompare.mStartingFloor == this->mStartingFloor;
        bool number = toCompare.mNumberOfPeople == this->mNumberOfPeople;
        return (destination && start && number);
    }
    People(const People& toMove){
        mNumberOfPeople = toMove.mNumberOfPeople;
        mStartingFloor = toMove.mStartingFloor;
        mDesignatedFloor = toMove.mDesignatedFloor;
    }
    People(){
        mNumberOfPeople = 0;
        mStartingFloor = 0;
        mDesignatedFloor = 0;
    }
    ~People(){
    }
};

#endif