#include <utility>

class People{
private:
    unsigned int numberOfPeople;
    int designatedFloor;
public:
    std::pair<decltype(numberOfPeople),decltype(designatedFloor)> getGroup();
    decltype(numberOfPeople) getPeopleumber();
    decltype(designatedFloor) getDestination();
};


std::pair<unsigned int,int> People::getGroup(){
    return std::pair<unsigned int,int>(0,0);
}

unsigned int People::getPeopleumber(){
    return 0;
}

int People::getDestination(){
    return 1;    
}
