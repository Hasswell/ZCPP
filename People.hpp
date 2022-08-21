#include <utility>
#include <cassert>
#include <tuple>

struct People{
    unsigned int mNumberOfPeople;
    int mDesignatedFloor;
    int mStartingFloor;
public:
    explicit People(unsigned int numberOfPeople, int designatedFloor,int startingFloor){
        assert(numberOfPeople > 0);
        mNumberOfPeople = numberOfPeople;
        mDesignatedFloor = designatedFloor;
        mStartingFloor = startingFloor;
    }
    People(int numberOfPeople, int designatedFloor,int startingFloor) = delete;
};